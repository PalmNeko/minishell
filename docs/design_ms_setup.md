# ms_setup
minishellを起動した際に行う処理。

## データ構造

- minishellで扱うデータを格納する構造体
  ```c
  typedef t_list ms_shell_var_list;
  typedef t_list ms_env_list;
  typedef t_list ms_malloc_list;

  typedef struct minishell{
	ms_shell_var_list *ms_shell_var;
	ms_env_list *ms_env;
	ms_malloc_list *ms_malloc_list;
  }t_minishell
  ```

	- シェル変数・環境変数格納用構造体
	```c
	typedef struct s_ms_var{
		char *name;
		char *value;
		int attr;
	}t_var
	```
	- メモリの動的確保を管理する構造体変数
	```c
	typedef struct s_ms_malloc{
		void *ptr;
	} t_ms_malloc
	```

### シェル変数
PWD: 現在の作業ディレクトリ
OLDPWD: 直前の作業ディレクトリ
CDPATH: cd検索パス
HISTCMD: 履歴番号
HISTFILE: 履歴ファイルのパス
HISTFILESIZE: 履歴ファイルのサイズ
HISTSIZE: メモリ内の履歴サイズ
TMPDIR: 一時ファイルのディレクトリ
PATH: コマンド検索パス
PS1: プライマリプロンプト(特殊文字考慮なし)
PS2: セカンダリプロンプト(特殊文字考慮なし)

## 処理

### 1.シェルの初期化
下記変数を初期化
- 環境変数
- シェル変数
- 動的にメモリ確保する変数を管理する構造体変数
#### ms_shell_var_list ms_initialize_shell_var(void);
**説明**
- 各変数について、下記処理を行ったあとシェル変数用の構造体変数に格納し、それを返す。

#### ms_env_list *ms_initialize_env(void);
**説明** 
- 外部変数`char **environ`を環境変数用の構造体変数に格納し、それを返す。

| 変数名 | 初期化時の挙動 |
|:--|:--|
| PWD | 起動時のカレントディレクトリ |
| OLDPWD | 未設定("") |
| CDPATH | 未設定("") |
| HISTCMD | `1` |
| HISTFILE | `~/.mnsh_history` |
| HISTFILESIZE | `HISTSIZEの値` |
| HISTSIZE | `500` |
| TMPDIR | `/tmp` |
| PATH | `**char environ(をminishell用に格納したもの)のPATHを継承` |
| PS1 | `minishell $ ` |
| PS2 | `> ` |
| MNSH_SUBSHELL | `0` |

### 2.キー入力のハンドリング
- シグナルの返り値 : 128+signo

#### ms_set_handle();
**説明** : Ctrl-C, Ctrl-D, Ctrl-\\ の入力に対するハンドラーのセット
  - Ctrl-C (SIGINT)
    - 入力待機時にSIGINTを受け取った場合に新しい行をreadlineライブラリを用いて出力する。
    - 非同期コマンドは、 継承したシグナルハンドラに加えて SIGINT も無視。
  - Ctrl-\ (SIGQUIT)
    - minishell内においては無視を行う。
		- (`signal.h`において`SIG_IGN`マクロが提供されている)
  - Ctrl-D
    - readline関数においてハンドラが設定されているため設定不要
	- readlineの挙動で、何も入力されてない時に押されるとEOFを返す。

## 3.ヒストリーの初期化
- 変数 HISTFILEに示すファイルの内容で履歴の初期化及び下記の変数代入を行う
| 変数名 | 初期化時の挙動 |
|:--|:--|
| HISTFILESIZE | `0` |
| HISTSIZE | `0` | 

## 4.TTYモードであるかどうかの判定
- mimishellが起動された時に対話モードであるかを判定する。
- minishell起動時に以下のような状態であれば、非対話モードである
	- 標準入力または標準エラー出力がisattyでない場合。
	- パイプで繋がれた実行 Ex:`echo "echo hoge" | ./minishell`
	- 実行がリダイレクトされている Ex: `./minishell >2 outfile` `infile > ./minishell`
