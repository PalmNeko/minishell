# 構文解析
# 宣言
`t_syntax_result	*ms_syntax_analyze(t_list *tokens)`

# 説明
tokensに対して構文解析を行いその結果を返す。
構文解析の結果は構文木で返される。
構文ノードが終端構文の場合は、tokensにトークンのリストが指定される。
構文ノードが非終端構文の場合は、childrenに終端構文もしくは非終端構文のリストが設定される。

# 戻り値

全ての戻り値(NULL含む)は、ms_destroy_syntax_resultの引数に指定して呼び出し可能である。

成功時、メモリに確保されたt_syntax_result型の値が返される。
構文として解析できなかった時、typeに`SY_DECLINED`、tokensに問題があったトークンの一個前の要素が入った、メモリに確保された値が返される。
エラー発生時、NULLが返され、適切な値がerrnoに設定される。

# エラー
ENOMEM malloc関連のエラー

# 構文の一覧

## 終端構文
| 名前 | 対応するt_syntax_type | 対応するBNF |
| --- | --- | --- |
| 拒否 | SY_DECLINED | 無し |
| 識別子要素 | SY_IDENTIFY | identify |
| 数値 | SY_NUMBER | number |
| 単語要素 | SY_WORD | word |
| 空白要素 | SY_BLANK | blank |
| 改行要素 | SY_NEWLINE | newline |
| 変数要素 | SY_VARIABLE | variable |
| パイプ要素 | SY_PIPE | pipe |
| 等号要素 | SY_EQUALS | equals |
| シングルクォート要素 | SY_SINGLE_QUOTE | single_quote |
| ダブルクォート要素 | SY_DOUBLE_QUOTE | double_quote |
| リダイレクト要素 | SY_REDIRECTION | redirection |
| 左かっこ要素 | SY_LEFT_PARENTHESIS | left_parenthesis |
| 右かっこ要素 | SY_RIGHT_PARENTHESIS | right_parenthesis |
| トークンリスト要素 | SY_LIST_TOKEN | list_token |
| 全要素 | SY_ALL | all |

## 非終端構文
| 名前 | 対応するt_syntax_type | 対応するBNF |
| --- | --- | --- |
| ダブルクォートで囲まれた単語 | SY_DOUBLE_QUOTED_WORD | double_quoted_word |
| シングルクォートで囲まれた単語 | SY_SINGLE_QUOTED_WORD |single_quoted_word |
| 単語リスト | SY_WORD_LIST | word_list |
| 代入単語 | SY_ASSIGNMENT_WORD | assignment_word |
| リダイレクト単語 | SY_REDIRECTION_WORD | redirection_word |
| 単純コマンド | SY_SIMPLE_COMMAND | simple_command |
| コマンド | SY_COMMAND | command |
| パイプライン | SY_PIPELINE | pipeline |
| リスト | SY_LIST | list |
| 複合リスト | SY_COMPOUND_LIST | compound_list |
| ユーザー入力 | SY_USER_INPUT | user_input |
| 命令 | SY_INSTRUCTION | instruction |

# BNF記法

## 事前定義

以下の定義は、字句解析で分割したトークンとして参照される。
各定義は、終端構文とする。
| name | t_token_type |
| --- | --- |
| identify | TK_IDENTIFY |
| number | TK_NUMBER |
| word | TK_WORD |
| blank | TK_BLANK |
| newline | TK_NEWLINE |
| variable | TK_VARIABLE |
| pipe | TK_PIPE |
| equals | TK_EQUALS |
| single_quote | TK_SINGLE_QUOTE |
| double_quote | TK_DOUBLE_QUOTE |
| redirection | TK_REDIRECTION |
| left_parenthesis | TK_LEFT_PARENTHESIS |
| right_parenthesis | TK_RIGHT_PARENTHESIS |
| list_token | TK_LIST |

## BNF

構文解析で解析する文法の定義。
> 構文木には含まない要素も含まれている。

> 構文の記述
> *: 直前の要素の0回以上の繰り返し
> +: 直前の要素の1回以上の繰り返し
> ?: 直前の要素が0個か1個
> (): グループ化
> `<<name>>`: 疑似要素。概念で定義されたもの。

```md
# 終端構文
<all> ::= 全ての種類のトークン

# クォート
<double_quoted_word> ::= <double_quote> <all>* <double_quote>
<single_quoted_word> ::= <single_quote> <all>* <single_quote>

# ワード
<word_list> ::= <word_list> <word_list> | <identify> | <word> | <double_quoted_word> | <single_quoted_word> | <variable> | <number>

# コマンド
<assignment_word> ::= <identify> <equals> <word_list>
<redirection_element> ::= <number> <redirection> | <redirection>
<redirection_word> ::= <redirection_element> <word_list> | <redirection_element> <blank> <word_list>
<simple_command> ::= <assignment_word> | <word_list> | <redirection_word> | <simple_command> <blank> <simple_command>
<command> ::= <simple_command>

# パイプライン
<pipeline> ::= <blank>? <command> <blank>? | <pipeline> <pipe> <pipeline>

# リスト
<list> ::= <pipeline> | <pipeline> <list_token> <pipeline> | <compound_list>
<compound_list> ::= <left_parenthesis> <list> <right_parenthesis>

# 入力（ヒアドクで使用）
<user_input> ::= <all> | <user_input> <user_input>

# 命令 ここが最初
<instruction> ::= <list> | <list> <newline> | <list> <newline> <user_input>

```

# 構造体
```c

// 構文の種類
typedef enum e_syntax_type {
	// 終端構文
	SY_DECLINED, // 拒否
	SY_IDENTIFY, // 識別子要素
	SY_NUMBER, // 数値
	SY_WORD, // 単語要素
	SY_BLANK, // 空白要素
	SY_NEWLINE, // 改行要素
	SY_VARIABLE, // 変数要素
	SY_PIPE, // パイプ要素
	SY_EQUALS, // 等号要素
	SY_SINGLE_QUOTE, // シングルクォート要素
	SY_DOUBLE_QUOTE, // ダブルクォート要素
	SY_REDIRECTION, // リダイレクト要素
	SY_LEFT_PARENTHESIS, // 左かっこ要素
	SY_RIGHT_PARENTHESIS, // 右かっこ要素
	SY_LIST_TOKEN, // トークンリスト要素
	SY_ALL, // 全要素

	// 非終端構文
	SY_DOUBLE_QUOTED_WORD, // ダブルクォートで囲まれた単語
	SY_SINGLE_QUOTED_WORD, // シングルクォートで囲まれた単語
	SY_WORD_LIST, // 単語リスト
	SY_ASSIGNMENT_WORD, // 代入単語
	SY_REDIRECTION_WORD, // リダイレクト単語
	SY_SIMPLE_COMMAND, // 単純コマンド
	SY_COMMAND, // コマンド
	SY_PIPELINE, // パイプライン
	SY_LIST, // リスト
	SY_COMPOUND_LIST, // 複合リスト
	SY_USER_INPUT, // ユーザー入力
	SY_INSTRUCTION, // 命令
}	t_syntax_type;

// 構文木のノード
typedef struct s_syntax_node	t_syntax_node;
typedef struct s_syntax_node {
	t_syntax_type 	type; // 構文の種類
	t_list			*token; // トークン。終端構文で使用。
	t_list			*children; // 子構文のリスト。t_syntax_tree型の値を保管するリスト。非終端構文で使用。
}	t_syntax_node;

// 構文木
typedef struct s_syntax_result {
	t_syntax_node *root; // 一番先頭の構文 (instruction)
}	t_syntax_result;

```

# その他の関数

## 構文ノード作成関数

**宣言**
```c
// 終端構文
t_syntax_node	*ms_parse_declined(t_list *tokens);
t_syntax_node	*ms_parse_identify_element(t_list *tokens);
t_syntax_node	*ms_parse_word_element(t_list *tokens);
t_syntax_node	*ms_parse_equals_element(t_list *tokens);
t_syntax_node	*ms_parse_redirection_element(t_list *tokens);
t_syntax_node	*ms_parse_delimiter_element(t_list *tokens);
t_syntax_node	*ms_parse_merged_word(t_list *tokens);

// 非終端構文
t_syntax_node	*ms_parse_assignment_word(t_list *tokens);
t_syntax_node	*ms_parse_redirection_word(t_list *tokens);
t_syntax_node	*ms_parse_simple_command(t_list *tokens);
t_syntax_node	*ms_parse_command(t_list *tokens);
t_syntax_node	*ms_parse_pipeline(t_list *tokens);
```

**説明**
構文に沿った構文ノードを作成する関数群。
各tokensは、構文解析を行うためのトークンの最初のリストである。

**戻り値**
成功時、メモリに確保された構文ノードを返す。
エラー時、NULLを返し、errnoに適切な値を設定する。

**エラー**
ENOMEM malloc関連のエラー

## t_syntax_node関連の関数

**宣言**
```c
t_syntax_node	*ms_create_syntax_node(t_syntax_type type);
void			ms_destroy_syntax_node(t_syntax_node *node);
t_syntax_node	*ms_append_node_syntax_node(t_syntax_node *parent, t_syntax_node *child);
t_syntax_node	*ms_append_token_syntax_node(t_syntax_node *parent, t_token *token);
void			ms_print_syntax_node(t_syntax_node *node);
void			ms_print_syntax_node_recursive(t_syntax_node *node);
// 必要になったときに
/*
typedef void	*(*t_iter_func)(t_syntax_node *node, int depth);

void			ms_iter_syntax_node(t_syntax_node *node, t_iter_func f);
void			ms_copy_syntax_node(t_syntax_node *node);
void			ms_copy_syntax_node_recursive(t_syntax_node *node);

*/
```

**説明**
* **ms_create_syntax_node** typeの構文ノードを作成する。children, tokensの初期値はNULL
* **ms_destroy_syntax_node** 構文ノードで使用しているメモリを開放する。NULLポインタが指定された場合は何もしない。
* **ms_append_syntax_node** parentノードのchildrenにchildノードを追加する。
* **ms_append_syntax_node** parentノードのtokensにtokenを追加する。
* **ms_print_syntax_node** nodeを一つ標準出力に出力する。
* **ms_print_syntax_node_recursive** nodeを再帰的にchildrenのノードも出力する。

**戻り値**
戻り値があるものはその型に応じて次に従う。

* **ms_create_syntax_node** は、成功時、メモリ上に作成したノードへのポインタ、失敗時、NULL.
* **ms_append**系の関数は、成功時、parentのアドレス。失敗時、NULL.

戻り値がある関数はerrnoに適切な値を設定する。

**エラー**
ENOMEM malloc関連のエラー

## t_syntax_result関連の関数
**宣言**
```c
t_syntax_result	*ms_create_syntax_result(t_syntax_node *node)s;
void			ms_destroy_syntax_result(t_syntax_result *result);
```

**説明**
**ms_create_syntax_result** rootにnodeが入った構文解析の結果を作成する。
**ms_destroy_syntax_result** メモリを開放する。NULLが指定されたときは、何もしない。

**戻り値**
* **ms_create_syntax_result** 成功時、構文解析の結果。エラー時NULL
エラー時、errnoに適切な値が設定される。

**エラー**
ENOMEM malloc関連のエラー
