# ms_setup
minishellのsetup

## データ構造

- minishellで扱うデータを格納する構造体
  ```c
  typedef struct minishell{
	t_ms_env_var_list env_var_list;
	t_ms_shell_var_list shell_var_list;
	t_malloc tmalloc;
  }t_minishell
  ```

- シェル変数・環境変数格納用構造体

  ```c
  typedef struct ms_var{
  	char *name;
  	char *value;
  }t_ms_var

  typedef struct ms_env{
  	t_ms_var *env;
  	ms_env *next;
  } t_ms_env

  typedef struct ms_shell_var {
  	t_ms_var *shell_var;
  	ms_shell_var *next;
  } t_shell_var;

  typedef struct ms_env_list{
  	ms_env *top;
  } t_ms_env_list

  typedef struct ms_shell_var_list {
  	shell_var *top;
  } t_ms_shell_var_list;

  ```
- メモリの動的確保を管理する構造体変数
```c
struct struct s_malloc(){
	void *ptr;
	struct s_malloc *next;
} t_malloc
```

### シェル変数
MNSH: bashの完全なパス名
MNSHPID: 現在のminishellプロセスのプロセスID
SHLVL: 現在のシェルの階層数
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
IFS: 内部フィールドセパレータ

MNSH_SUBSHELL: サブシェルのネストレベル

## 処理
### 1.シェルの初期化
下記変数を初期化
- 環境変数
- シェル変数
- 動的にメモリ確保する変数を管理する構造体変数
#### ms_env_list *ms_initialize_env(void);
**説明** 
- 外部変数`char **environ`をms_envに格納し、ms_env_listのアドレスを返す。
 
#### ms_shell_var_list ms_initialize_shell_var();
**説明**
- 各変数について、下記処理を行ったあとms_shell_varに格納し、ms_shell_var_listのアドレスを返す。
| 変数名 | 初期化時の挙動 |
|:--|:--|
| MNSH | `argv[0]` |
| MNSHPID | 起動時のプロセスID |
| SHLVL | 現在のシェルの階層数 |
| PWD | 起動時のカレントディレクトリ |
| OLDPWD | 未設定("") |
| CDPATH | 未設定("") |
| HISTCMD | `1` |
| HISTFILE | `~/.mnsh_history` |
| HISTFILESIZE | `0` |
| HISTSIZE | `0` |
| TMPDIR | `/tmp` |　<- 要確認お願いします
| PATH | `**char environ(をminishell用に格納したもの)のPATHを継承` |
| PS1 | `minishell $ ` |
| PS2 | `> ` |
| IFS | `<space><tab><newline>` |
| MNSH_SUBSHELL | `0` |

## 6.キー入力のハンドリング
- シグナルの返り値 : 128+signo
### ms_set_handle
**説明** : Ctrl-C, Ctrl-D, Ctrl-\\ の入力に対するハンドラーのセット
  - Ctrl-C (SIGINT)
    - 入力待機時にSIGINTを受け取った場合に新しい行をreadlineライブラリを用いて出力する。
    - 非同期コマンドは、 継承したシグナルハンドラに加えて SIGINT も無視。
  - Ctrl-\ (SIGQUIT)
    - minishell内においては無視を行う。(`signal.h`において`SIG_IGN`マクロが提供されている)
  - Ctrl-D
    - readline関数においてハンドラが設定されているため設定不要

## 7.ヒストリーの初期化
- 変数 HISTFILEに示すファイルの内容で履歴の初期化及び下記の変数代入を行う
| 変数名 | 初期化時の挙動 |
|:--|:--|
| HISTFILESIZE | `0` |
| HISTSIZE | `0` | 

## 8.サブシェルの初期化
調査中m(_ _)m
