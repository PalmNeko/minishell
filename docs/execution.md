# 単純コマンドの実行
# 宣言
```c
int	ms_command_execution(t_lsa_command *lsa);
```

# 説明
意味解析の結果からコマンドを実行する。
コマンドが存在するときとしないときで共同が異なり、
コマンドがあるときは以下の挙動となる。
1. コマンドの展開
1. FD(0,1,2)と環境変数の保存
1. 環境変数の代入（エラー発生時でも処理を続ける）
1. リダイレクションの実行
1. コマンドの実行
1. FD(0,1,2)と環境変数のリストア

コマンドがないときは以下の挙動となる。
1. 環境変数の代入
1. リダイレクションの実行

各処理はフローのセクションを参考にすること。

# 戻り値
- コマンドの実行の実行ができたとき、`ms_execute_command`関数の戻り値をそのまま返す。
- 環境変数の代入やリダイレクションで失敗して終了する必要があるときは、`1`を返す。
- メモリ不足でエラーが発生したときは、`-1`を返す。

# エラー
- ENOMEM メモリ不足で終了したとき

# フロー
単純コマンドは以下の順に処理が行われる。
```mermaid
flowchart TD
	ms_command_execution[コマンドの実行]
		--> ms_expand_commands[コマンドの展開]
		--> ms_has_any_commands{コマンドがある？}
		ms_has_any_commands --> |yes| ms_overwrite_environ[[環境変数の書き換え]]
		ms_has_any_commands --> |no| ms_simple_command_execution[[コマンドの実行]]
```

```mermaid
flowchart TD
	ms_overwrite_environ[[環境変数の書き換え]]
		--> ms_run_assignment_variable[環境変数の設定（エラー時環境の書き換え終了）]
		--> ms_run_redirection[リダイレクションの展開]
```

```mermaid
flowchart TD
	ms_simple_command_execution[[単純コマンドの実行]]
		--> ms_save_environ_memento[環境の保存]
		--> ms_run_assignment_variable[環境変数の設定（エラー時続行）]
		--> ms_run_redirection[リダイレクションの展開]
		--> ms_execute_command[[コマンドの実行]]
		--> ms_restore_environ_memento[[環境の復活]]
```


# 主な関数

 ## template ()
 - **宣言**:
 - **説明**:
 - **引数**:
 - **戻り値**
	 - **成功時**: 複製された情報へのポインタ
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

## ms_save_exec_mement ( 実行環境の保存 )
- **宣言**:
```c
t_environ_memento *ms_save_exec_memento(char *const envp[]);
```
- **説明**:
以下の情報を構造体に複製して保存する。
	* 現在の標準入力のFD
	* 現在の標準出力のFD
	* 現在の標準エラー出力のFD
	* 現在の環境変数

	FDは、dupを使って複製される。
- **戻り値**
	- **成功時**: 複製された情報へのポインタ
	- **失敗時**: NULL
- **エラー**:
  - **ENOMEM**: malloc関連のエラー
  - **EBADF**: dup関連のエラー
  - **EMFILE**: dup関連のエラー
- **構造体**:
```c
// 実行環境の構造体（環境変数とはべつ）
typedef struct s_environ_memento {
	char *const	envp[]; // 環境変数
	int	stdin_fd; // 標準入力のFD
	int	stdout_fd; // 標準出力のFD
	int	stderr_fd; // 標準エラー出力のFD
}	t_environ_memento;
```

## ms_expand_commands (コマンドの展開)
- **宣言**:
```c
char	**ms_expand_commands(t_lsa_word_list **args);
```
- **説明**:
 引数のargsの各要素に対して、展開処理(ms_expansion)を行った結果をNULL終端の配列で返す。
- **引数**:
	- **args**: NULL終端の配列
- **戻り値**
	- **成功時**: NULL終端の配列
	- **失敗時**: NULL
- **エラー**:
  - **ENOMEM**: malloc関連のエラー

 ## ms_has_any_commands (コマンドがあるかどうかの判定)
 - **宣言**:
 ```c
bool	ms_has_any_commands(char **ntp)
 ```
 - **説明**: コマンドがあるかどうかを判定する。
 - **引数**:
	 - **ntp**: NULL終端の配列。
 - **戻り値**
	 - **true**: 一番目の要素に、長さが１以上の文字列が入っている時。
	 - **false**: それ以外の場合
 - **エラー**: なし

 ## ms_overwrite_environ (環境変数の書き換え)
 - **宣言**:
 ```c
 int ms_overwrite_environ(s_lsa_assignment **assignments);
 ```
 - **説明**:
 assignmentsから各代入式を実行して、グローバルな変数を書き換える。（内部で環境変数を渡して処理する同様の関数があると良さげ。）
 - **引数**:
	 - **assignments**: NULL終端の配列
 - **戻り値**
	 - **成功時**: 0を返す。
	 - **失敗時**: 1を返す。読み込み専用の変数に代入しようとしたとき等に失敗。
	 - **エラー時**: -1 を返し、errnoに値が設定される。
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_simple_command_execution (コマンドの実行)
 - **宣言**:
 ```c
 int ms_simple_command_execution(char **args)
 ```
 - **説明**:
 現在の環境で、argsのコマンドを実行する。args[0]がコマンドとして認識され、args[1]以降は、引数として扱われる。
 args[0]は、PATHが設定されいてかつ、`/`が含まれないときに、PATH変数を使って展開処理が行われる。
 PATH変数を使って展開処理を行わない場合はそのままexecveに渡される。
 specificationのPATH変数の内容を確認してください。
 また、各argsはパラメータ展開(*)される必要があります。展開される対象は、クォートされていないもののみです。
 コマンドが展開された後は、execveによって、実行されます。
 より詳細な説明は、仕様（specification.md）を参考に作成してください。
 - **引数**:
	 - **args**: NULL終端の配列
 - **戻り値**
	 - **126**: execveが次のerrnoで失敗した場合。127番以外の理由で失敗したとき。
	 - **127**: 次の場合にこの番号で終了します。
		 - ENOENT, EFAULTで失敗したとき。
		 - コマンドのパスをPATH変数を使って展開した場合に、ファイルが存在しなかった場合。
		 - そのほかのエラーの場合。
	 - **成功時**: 戻り値無し
 - **エラー**:
     - 基本的にexecveのエラーを確認。
 - **エラーメッセージ**:
	 - 以下の場合に、エラー文のフォーマットに沿って、`command not found`を出力する。
	     - PATHを検索したが、対象のコマンドが見つからなかったとき。
	 - それ以外の時は、perrorに順ずるエラーメッセージをフォーマットに沿って出力する。


# 補足


### 2. コマンドの展開
ここでは、リダイレクションでも変数代入でもないワードを展開し、引数として処理します。

### 3. 変数代入の実行
ここでは、順に環境変数に値を設定する。

### 3. コマンドの検索
コマンドと環境変数から

### 2. リダイレクション（ヒアドク含む）の実行
ここでは、リダイレクションするファイルを順に開き、それに対して、入出力のリダイレクションを行う。ヒアドクの処理も同様に行う。

### 4. コマンドの実行
コマンドを実行する。

### 5. 実行環境の復元
コマンドがない場合は、大元の実行環境に現在の環境変数のみを適用させる。（ファイルディスクリプタは適用しない）
コマンドがあった場合は、元の実行環境に戻す。
外部コマンド（execve）の実行が成功したときにはここに来ない。

## 展開

各ワードにに対しては、展開処理が行われる。
この展開処理は以下の処理を順に行った結果となる。結果はNULL終端配列で表される。
1. パラメータと変数の展開
2. パス名展開
