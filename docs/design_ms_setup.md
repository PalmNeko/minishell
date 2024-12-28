# t_minishell *ms_setup(void);
**説明**
minishellを起動した際に行う処理。
minishellで扱うデータの領域確保・初期化を行い、それを返す。
**エラー**
メモリの領域確保に失敗した時にエラーを返す。


## データ構造

- minishellで扱うデータを格納する構造体
  ```c
  typedef t_list ms_var_list;
  typedef t_list ms_malloc_list;

  typedef struct minishell{
	ms_var_list *ms_shell_var;
	ms_malloc_list *ms_malloc_list;
  }t_minishell
  ```

	- 状態管理用構造体
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

### minishellの状態管理に用いる変数
#### 環境変数
- ①親プロセスから引き継いだ環境変数
- ②minishell内において新たにエクスポートされた環境変数
上記２種類の環境変数で構成される。

#### シェル変数
minishellの状態を表すための変数。説明は下記の通りである。
| 変数名         | 説明                                         | 初期化時の挙動                                      |
|:---------------|:---------------------------------------------|:--------------------------------------------------|
| PWD            | 現在の作業ディレクトリ                       | 起動時のカレントディレクトリ                       |
| OLDPWD         | 直前の作業ディレクトリ                       | 未設定("")                                        |
| CDPATH         | `cd`コマンドの検索パス                       | 未設定("")                                        |
| HISTCMD        | 履歴番号                                     | `1`                                              |
| HISTFILE       | 履歴ファイルのパス                           | `~/.mnsh_history`                                |
| HISTFILESIZE   | 履歴ファイルのサイズ                         | `HISTSIZEの値`                                   |
| HISTSIZE       | メモリ内の履歴サイズ                         | `500`                                            |
| TMPDIR         | 一時ファイルのディレクトリ                   | `/tmp`                                           |
| PATH           | コマンド検索パス                             | **char environ(をminishell用に格納したもの)のPATHを継承** |
| PS1            | プライマリプロンプト(特殊文字考慮なし)       | `minishell $ `                                   |
| PS2            | セカンダリプロンプト(特殊文字考慮なし)       | `> `                                             |
| MNSH_SUBSHELL  | サブシェルモードかどうかを示す変数           | `0`                                              |

#### 変数の属性
|属性名 |説明 |
|:--|:--|
|ATTR_NONE | 属性を持たない。|
| ATTR_SHELL_VAR | シェル変数である。|
| ATTR_ENV | minishell起動時にもともと存在していた環境変数である。|
| ATTR_EXPORT | minishell内で新たにエクスポートされた変数である。|

## 処理

### シェルの初期化
#### 状態管理用構造体変数の初期化
**説明**
- 親プロセスより取得した環境変数を格納し、`ATTR_ENV`属性を設定。
- (シェル変数)[シェル変数] の項目に書かれている変数を表に記載している初期化処理を行い格納した後、`ATTR_SHELL_VAR`属性を設定。

#### 動的にメモリ確保する変数を管理する構造体変数
**説明**
- 構造体変数の領域を確保したのち、状態管理用構造体の確保に用いた動的メモリのポインタを登録する。

### キー入力のハンドリング
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

### ヒストリーの初期化
- 変数 HISTFILEに示すファイルの内容で履歴の初期化及び下記の変数代入を行う

| 変数名	| 初期化時の挙動 |
|:--	|:--	|
| HISTFILESIZE | `0` |
| HISTSIZE | `0` | 

### TTYモードの判定
- mimishellが起動された時に対話モードであるかを判定する。
- minishell起動時に以下のような状態であれば、非対話モードである
	- 標準入力または標準エラー出力がisattyでない場合。
	- パイプで繋がれた実行 Ex:`echo "echo hoge" | ./minishell`
	- 実行がリダイレクトされている Ex: `./minishell >2 outfile` `infile > ./minishell`
