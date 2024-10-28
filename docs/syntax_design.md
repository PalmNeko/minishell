
# 構文解析 ms_parse

## 宣言

`t_syntax_node *ms_parse(t_list *tokens)`

## 説明

ms_tokenizeの戻り値である、リストのtokensを構文木に直す。構文木の形は下記参照。

## 戻り値

## エラー

## 構文木の構造

### 構文
bashの構文は、BNF記法を用いて下記のようにあらわせるものとする。

```
list = pipeline ("&&" pipeline | "||" pipeline)*
pipeline = statement ("|" statement)*
statement = (environ | redirection)* command (argument | redirection)
environ = name "=" value?
redirection = fd? ("<" | ">" | ">>" | "<<" "-"? ) string

name = アルファベット、数字、アンダースコアのみから成り、アルファベットかアンダースコアから始まる単語。識別子とも呼ばれる。
value = 文字列
fd = 符号なしの数値 ex. 0001, 000, 123 (符号をつけた場合文字列として扱われる)
string = 文字列
word = 文字列
command = 文字列
```

### 例

## データ型
```c

//
typedef enum  e_syntax_type t_syntax_type;
enum e_syntax_type {
	TS_LIST_ANY, // ;
	TS_LIST_AND, // &&
	TS_LIST_OR, // ||
	TS_PIPELINE, // |
	TS_ENVIRON, // 環境変数代入
	TS_ARGUMENT, // 引数（コマンドを含む）
	TS_REDIRECTION, // < > >>
	TS_HEREDOC, // <<
};


// 構文木
typedef struct s_syntax_tree t_syntax_tree;
struct s_syntax_tree {
	t_list *plist; // t_plist型のデータを持つリスト
};

// リスト
typedef struct s_plist t_plist;
struct s_plist {
	t_syntax_type type; // 取りうる値は、TS_LIST* のみ
	t_list *pipelines; // t_pipeline型のデータを持つリスト
}

// パイプライン
typedef struct s_pipeline t_pipeline;
struct s_pipeline {
	t_syntax_type type; // 取りうる値は、TS_PIPELINE* のみ
	t_list *commands; //
}

// コマンド
typedef struct s_command t_command;
struct s_command {
	t_syntax_type type; // 取りうる値は、TS_ARGUMENTのみ
	t_list *assignment; // 文字列型のデータを持つリスト。環境変数代入式(ex. VAR=123)。
	t_list *redirection; // t_redirection型のデータを持つリスト。
	t_list *args; // 文字列型のデータを持つリスト。引数は0番目から保存している。
}

// リダイレクション
typedef struct s_redirection t_redirection;
struct s_redirection {
	t_syntax_type type; // 取りうる値は、TS_REDIRECTION か TS_HEREDOC
	char *redirection; // リダイレクション。ex. "<" や "4>", "<<-"
	char *file_name; // ファイル名 or delimiter
}


```
