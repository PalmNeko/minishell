# ビルトインコマンド仕様

## 概要
minishell内部の組み込みコマンドの実装仕様。各関数の引数はexecve(2)に準拠。

```c
int execve(const char *path, char *const argv[], char *const envp[]);
```

### ビルトインで使うシェル変数
- PWD
- OLDPWD
- CDPATH
- PATH

### データ構造
- **builtin_command_list**:
  ``` c
  typedef struct s_cmd_list{
  	char *cmd;
  	int (*func)();
  } t_cmd_list

  ["echo", "cd", "pwd", "export", "unset", "env", "exit"]
  ```

## コマンドフロー
```mermaid
flowchart
AA[ms_builtinの関数であるとき]
A[ms_builtin]
B[ms_builtin_echo]
C[ms_builtin_cd]
D[ms_builtin_pwd]
E[ms_builtin_export]
F[ms_builtin_env]
G[ms_builtin_exit]

H["cmd = argv[1]"]
I{cmd in builtin_list}
J["output('Command not found')"]
K["next"]

AA --> H --> A --> I
I --> B
I --> C
I --> D
I --> E
I --> F
I --> G
I --> J --> K
```

## コマンド一覧

### ms_builtin
```c
int ms_builtin(const char *path, char *const argv[], char *const envp[])
```
- **説明**:
  -  argv[0]に対応するビルトイン関数の実行
- **戻り値**:
  - 実行先関数の終了ステータスを返す

### ms_builtin_func common
- **エラー**
  -  invalid option(オプションが不正な時)
    ```
    minishell: <cmd>: -<opt>: invalid option
    <cmd>: usage: <cmd> [able_opt]
    ```
  - 終了ステータスは2を返す。
 
### ms_builtin_echo
```c
int ms_builtin_echo(const char *path, char *const argv[], char *const envp[])
```
- **構文**: `echo -n [arg...]`
- **説明**
  - argを空白区切りで標準出力に出力し、最後に改行を出力
- **オプション**
  - -n : 最後の改行が出力されない。
  - `-n`以外はすべて出力文字列として認識する。
- **戻り値**
  -  常に0

### ms_builtin_cd
```c
int ms_builtin_cd(const char *path, char *const argv[], char *const envp[])
```
- **構文**: `cd [-L | -R[-e]] [dir]`
- **説明**
  - カレントディレクトリをdirに変更
  - デフォルト値として**HOME**が設定されている。
  - **CDPATH**はdirを含むディレクトリの検索パスを定義
    - **CDPATH**内の候補ディレクトリは`:`で区切られる。
    - **CDPATH**内の空のディレクトリはカレントディレクトリを意味する。
  - dirが`/`で始まる時、**CDPATH**は使われない。 
  - 引数が"-"であるとき、**$OLDPWD**に移動し、新しいディレクトリの絶対パス名が標準出力に表示される。
  - **CDPATH**内の空以外のディレクトリ名が使われたときや、`-`が最初の引数の時にディレクトリの変更が成功すると新しいディレクトリの絶対パス名をSTDOUTに出力。
- **オプション**
  - -L : シンボリックを辿って探索を行う。（デフォルトの挙動） 
  - -P : シンボリックリンクではなく物理的なディレクトリ構造を参照
  - -e : -Pオプションと同時に指定した際に、ディレクトリ変更に成功し、カレントディレクトリが判定出来ない場合に失敗ステータスを返す。
  - **シンボリックリンクの判定**
    - `lstat(2)`で得られた`buf.st_mode`においてフラグ`S_IFLNK`が該当すればシンボリックリンクである。
    - getcwd()でシンボリックリンクを参照するとリンク先にたどり着いてしまうため、PWD設定時にはgetcwdを使わない方が良さそう。
- **戻り値**:
  - 成功: 0
  - 失敗:
    - 1(`EISDIR`,`ENOENT`,`EACCESS`,`too many argments`)
    - 2(`invalid Option`)
- **エラー**:
  - too many arguments
    - dirが2つ以上の時
- **ref**
  - https://ja.manpages.org/stat/2
  - playgrond/ms_builtin/firs_prot_builtinよりプロトタイプも作成しています。
    - FirstProtTypeはnooptと-Pオプション($PWDの中身やエラーハンドリングなどは非対応）のみ対応
- **例**
  	``` bash
	$ pwd
	[...]/current_dir
	$ cd symboric_1 && pwd && cd ../
	[...]/current_dir/symboric_1
	$ cd -L symboric_1 && pwd && cd ../
	[...]/current_dir/symboric_1
	$ cd -P symboric_1 && pwd && cd ../
	[...]/current_dir/physical_dir
	```

### ms_builtin_pwd
```c
int ms_builtin_pwd(const char *path, char *const argv[], char *const envp[])
```
- **構文**: `pwd`
- **説明**
  -  現在の作業ディレクトリの絶対パス名(\$PWD)を表示
- **戻り値**:
  - 成功: 0
  - 失敗: invalid option -> 2
- **エラー**
  - invalid option  
- **特記**: カレントのPermissionが000でも動作

### ms_builtin_export
```c
int ms_builtin_export(const char *path, char *const argv[], char *const envp[])
```
- **構文**:
  `export [name[=word]]`
- **説明**:
  -  nameに印をつける。このnameはこれ以降の環境にエクスポートされる。
  -  変数名に`=word`が続くと`変数名`の値として`word`が格納される。
  -  引数がない場合はこのシェル内でエクスポートされている全ての名前のリストの出力。
- **戻り値**:
  - 成功: 0
  - 失敗:
    1 : invalid identifier
    2 : invalid option
- **エラー**: invalid identifier (nameに無効な文字が含まれる)

### ms_builtin_unset
```c
int ms_builtin_unset(const char *path, char *const argv[], char *const envp[])
```
- **構文**:
  `unset [name...]`
- **説明**: 
  - nameに対応する変数を削除する。
  - 読み込み専用の変数の設定を指定時のみ失敗。
  - 設定が消された変数や関数はすべて、それ以降の環境から削除される。
- **戻り値**:
  - 成功: 0
  - 失敗: 1

### ms_builtin_env
```c
int ms_builtin_env(const char *path, char *const argv[], char *const envp[])
```
- **構文**:
  `env`
- **説明**: 現在の環境変数をすべて表示
- **戻り値**: 常に0

### ms_builtin_exit
```c
void ms_builtin_exit(const char *path, char *const argv[], char *const envp[])
```
- **構文**: `exit [status]`
- **説明**: シェルを終了
  - statusが指定された場合: その値を終了ステータスとして使用
  - statusが未指定の場合: 直前のコマンドの終了ステータスを使用
  - エラーの場合：下記のエラーに対応する出力を行い終了処理を行う。
- **エラー**:
  - numeric argument required (statusが数値以外)
  - no such file or directory
  - not a directory
  - permission denied (実行権限なし)
  - too many arguments (引数が2個以上)
- **注意**: finalize処理と関連あり
