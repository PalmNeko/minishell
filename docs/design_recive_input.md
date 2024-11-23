# ユーザーからの入力受取 (ms_input)

## WorkFlow
``` mermaid
flowchart
AA[initialize]
A["ms_input_wait"]
B{"recived_string"}
C{"ms_input_check_closing"}
D["ms_input_error_not_close"]
D_1["status=2"]
E{"heredoc
now?"}
E_1{"heredoc
start?"}
E_2["ms_input_heredoc_init"]
F["ms_input_heredoc"]
F_1{heredoc_finish?}
G["add_history"]
H["exec part"]
I["free(recived_string)"]
Z["finishlize"]

AA --> A
A --> B
B --> |"no input"| I
B --> |EOF| Z
B -->|"OTHER"| C
C -->|"NO_CLOSED"| D --> D_1 --> I
C -->|"CLOSED"| E

E -->|"Yes"| F
E -->|"No"| E_1
E_1 -->|"Yes"| E_2 --> I
E_1 -->|"No"| G --> H --> I

F --> F_1
F_1 -->|"Yes"| G
F_1 -->|"No"| I

I --> A
```


## Variable
`char *cmdline (Default = "")`
- コマンドラインからの入力を格納する変数。
- ms_input_waitで出力した文字列を格納する。

`int input_status (Default = 0)`
- プロンプト出力状態の確認に使う。
- **出力文字**
	- 0:PS1
	- 1:PS2

`int closing_flag (Default = 0)`
- クォート、括弧が閉じられているかどうか判別するフラグ。
- `"` `'` `(` `)` のような閉じる必要のある文字についてそれぞれビットフラグを立てて管理する。

``` c
typedef struct s_heredoc_list{
	char *line;
	struct s_heredoc_list *next;
}t_heredoc_list

typedef struct s_delimiter_list{
	char *delimiter;
	struct s_delimiter_list *next;
}t_delimiter_list

typedef struct s_heredoc{
	int heredoc_count;
	t_delimiter *delimiter_list;
	t_heredoc_list *head;
	t_heredoc_list *tail;
}t_heredoc
```
- heredoc用の構造体変数
	`heredoc_count (Default = 0)`
	- heredocの個数を格納する。
	`

	`t_heredoc_list`
	`t_heredoc`

	- heredoc中に入力された文字列を格納するリスト。
	- t_heredocのheadが最初のheredocを指す。 

	`t_delimiter_list`
	- delimiterを格納するリスト。左から先頭に格納される。
## function
### `char *ms_input_wait(int input_status)`
- **説明**
プロンプトを表示してreadline関数を用いてユーザーからの入力を待つ。  
input_statusの状態によって表示するプロンプトを変える。
- **返り値**
readline関数からの入力によって得られた文字列

### `int *ms_input_isvalid_token(char *cmdline)`
- **説明**
cmdlineで渡された文字列において下記文字が適切に処理されているか
-`(` `)` `'` `"`が閉じられているか 
-`( )`の中にmeta_token以外の文字列が入っているか
	- ex: OK -> `(echo hoge | wc)` , `(aaa)` 
	- ex: NG -> `( )`, `( | )`
- パイプ及びリストの間に文字列が入っているか
	- ex: OK -> `cat || cat | cat` , `cat&|cat`
		- `&`単体は今回メタ文字として扱わないため
	- ex: NG -> `cat ||| cat` , `cat |&& cat`
- **返り値**
	- 正常時は０を返す
	- 適切に処理されていない文字のうち一番最初の文字に対応する数値

### `void ms_input_error_not_close(int closing_flag)`
- **説明**
`closing_flag`のビットマスクに応じて、シンタックスエラーを出力


### `t_heredoc ms_input_heredoc_init(char *cmdline)`
- **説明**
	- cmdlineに応じた初期化を行った構造体を返す。
	- エラーのときはNULLポインタを返す。
	- `<<`の数を`heredoc_flag`に格納する。
	- `heredoc_flag`の数だけ、デリミタを格納する。
- **エラー**
	- `<<`のnext_tokenがmeta_tokenだった時、以下を出力
		- `syntax error near unexpected token <next_meta_token>`

### `void ms_input_heredoc(t_heredoc *heredoc)`
- **説明**
ヒアドキュメントの処理を行う。