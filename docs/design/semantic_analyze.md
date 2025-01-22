# 意味解析 (Latent Semantic Analysis - LSA)

# 宣言
```c
t_lsa *semantic_analyze(const t_syntax_node *node);
```

# 説明
構文解析の結果に対して意味解析（より実行しやすい形に変形）を行う。
もしも、`SY_USER_INPUT`が同じ層のノードにある場合は、ヒアドクのために以下の処理を行うこと。
1. `SY_USER_INPUT`のノードをms_set_readnodestream関数を使って設定すること。
2. ms_unset_readnodestreamを使って設定を解除すること。

# 戻り値
- **成功時**: t_lsa型へのポインタ
- **エラー時**: NULL

# エラー
mallocを行うためそれらのエラー。

# 構造体
```c
typedef enum e_lsa_list_type {
	LSA_LIST_ALWAYS, // ;
	LSA_LIST_AND, // &&
	LSA_LIST_OR, // ||
}	t_lsa_list_type;

typedef enum e_lsa_redirection_type {
	LSA_RD_INPUT, // <
	LSA_RD_OUTPUT, // >
	LSA_RD_APPEND, // >>
	LSA_RD_HEREDOC, // <<
}	t_lsa_redirection_type;

typedef struct s_lsa_word_list {
	t_syntax_node *word_list; // SY_WORD_LIST
}	t_lsa_word_list;

typedef struct s_lsa_assignment {
	t_lsa_word_list *name; // 変数名
	t_lsa_word_list *value; // 値
}	t_lsa_assignment;

typedef struct s_lsa_redirection {
	t_lsa_redirection_type type;
	//どちらかがNULL
	t_lsa_word_list *filename;
	t_lsa_word_list *delimiter;
	t_syntax_node **heredoc_input; // ヒアドクの入力
	bool is_expansion; // 変数展開するかどうか
}	t_lsa_redirection;

typedef struct s_lsa_command {
	t_lsa_word_list **args;
	t_lsa_assignment **assignments;
	t_lsa_redirection **redirects;
}	t_lsa_command;

typedef struct s_lsa_pipeline {
	t_lsa_command **commands;
}	t_lsa_pipeline;

typedef struct s_lsa_list t_lsa_list;
typedef struct s_lsa_list {
	t_lsa_list_type type;
	// pipelineとcompound_listのどちらかにしか入らない。
	// 片方がNULLならもう片方はnon-NULL。
	t_lsa_pipeline *pipeline;	// パイプライン
	t_lsa_list **compound_list; // NULL終端の配列
}	t_lsa_list;

typedef struct s_lsa {
	t_lsa_list **lists;
}	t_lsa;
```

# その他の関数
## LSA時の関数
### ms_lsa_list
- **宣言**
```c
t_lsa_list	*ms_lsa_list(const t_syntax_node *list_node);
```
- **説明**:
  ノードからt_lsa_list型のデータを作成する。
  typeが`LSA_LIST_COMPOUND_LIST`になる場合は、compound_listに再帰的に入れる。
- **引数**: `SY_LIST`のノード
- **戻り値**:
	- **成功時**: t_lsa_list型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**: semantic_analyzeと同様。

### ms_lsa_pipeline
- **宣言**
```c
t_lsa_pipeline	*ms_lsa_pipeline(const t_syntax_node *list_node);
```
- **説明**: ノードからt_lsa_pipeline型のデータを作成する。
- **引数**: `SY_PIPELINE`のノード
- **戻り値**:
	- **成功時**: t_lsa_pipeline型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**: semantic_analyzeと同様。

### ms_lsa_command
- **宣言**
```c
t_lsa_command	*ms_lsa_command(const t_syntax_node *list_node);
```
- **説明**: ノードからt_lsa_command型のデータを作成する。
- **引数**: `SY_COMMAND`のノード
- **戻り値**:
	- **成功時**: t_lsa_command型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**: semantic_analyzeと同様。

### ms_lsa_word_list
- **宣言**
```c
t_lsa_word_list	*ms_lsa_word_list(const t_syntax_node *list_node);
```
- **説明**: ノードからt_lsa_word_list型のデータを作成する。
- **引数**: `SY_WORD_LIST`のノード
- **戻り値**:
	- **成功時**: t_lsa_word_list型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**:
	- **ENOMEM**: malloc関連のエラー

### ms_lsa_assignment
- **宣言**
```c
t_lsa_assignment	*ms_lsa_assignment(const t_syntax_node *assignment_word);
```
- **説明**: ノードからt_lsa_assignment型のデータを作成する。
- **引数**: `SY_ASSIGNMENT_WORD`のノード
- **戻り値**:
	- **成功時**: t_lsa_assignment型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**:
	- **ENOMEM**: malloc関連のエラー

### ms_lsa_redirection
- **宣言**
```c
t_lsa_redirection	*ms_lsa_redirection(const t_syntax_node *redirection_word);
```
- **説明**:
	ノードからt_lsa_redirection型のデータを作成する。
	各メンバは、適切にt_syntax_node型から変換する。
	heredoc_inputは、ms_read_input_nodeで読み取り、delimiterを含まないところまでを結合したt_syntax_node型として扱うこと。
	また、typeが`LSA_RD_HEREDOC_TRIM`だった場合は、先頭の空白文字`\t` ` `を削除すること。
- **引数**: `SY_REDIRECTION_WORD`のノード
- **戻り値**:
	- **成功時**: t_lsa_redirection型のデータ
	- **失敗時**: NULL。errnoに値が設定される。
- **エラー**: semantic_analyzeと同様。

## 各構造体の解放

下記の構造体はメモリに確保される。
* t_lsa_word_list
* t_lsa_assignment
* t_lsa_redirection
* t_lsa_command
* t_lsa_pipeline
* t_lsa_list
* t_lsa
解放用の関数を作成し、再帰的に開放すること。
引数にNULLが渡されたときは、何もしないこと。

宣言のフォーマットはいかに従うこと。<*>はパターンマッチ。`*`も含まれているので注意すること。
```c
void	ms_lsa_<*>_destroy(t_lsa_<*>* <*>);
```

## ヒアドク用入力ストリーム
### ms_set_readnodestream
- **宣言**
```c
int ms_set_readnodestream(t_syntax_node **stream);
```
- **説明**:
  与えられた`stream`に対して読み取り操作を開始する準備を行います。ストリームの先頭位置を初期化し、以降の`ms_read_node`関数でのノード読み取りが正常に行えるように設定します。各ノードはコピーされ、`ms_unset_readstream`および、`ms_read_node`から参照可能である必要があります。
- **引数**:
  - `t_syntax_node **stream`: 読み取り対象のストリーム。null-terminatedで、各要素は`t_syntax_node`を指すポインタ。
- **戻り値**:
  - **成功時**: 0。
  - **失敗時**: -1。`errno`にエラーが設定されます。
- **エラー**: メモリ不足、または無効な引数が渡された場合。

---

### ms_unset_readnodestream
- **宣言**
```c
void ms_unset_readnodestream(void);
```
- **説明**:
  読み込まれなかったノードのリソースが解放されます。読み込まれた分のノードは、読み込んだ側が`ms_syntax_node_destroy`を使用し解放する必要があります。
  現在のノードストリームの設定を解除し、リソースを解放します。この関数を呼び出した後は、`ms_read_node`の動作が不定になります。
- **引数**: なし。
- **戻り値**: なし。
- **エラー**: なし。

### ms_read_node
- **宣言**
```c
t_syntax_node *ms_read_node(void);
```
- **説明**:
  現在設定されているストリームから次の`t_syntax_node`を読み取ります。ストリームはnull-terminatedであるため、終端に達した場合はNULLを返します。読み込んだノードは解放する必要があります。
- **引数**: なし。
- **戻り値**:
  - **成功時**: 次の`t_syntax_node`へのポインタ。
  - **失敗時**: NULL。ストリームの終端に達した場合。
- **エラー**: なし
