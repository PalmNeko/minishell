```c
typedef struct s_token {
	t_token_type	type;
	char			*token; // メモリに確保された文字列
	int				end_pos; // 入力文字列に対する、トークン外の文字の開始位置
	int				start_pos; // 入力文字列に対する、トークンの開始位置
}	t_token;

typedef struct s_syntax_node {
	t_syntax_type 	type; // 構文の種類
	t_token			*token; // トークン。終端構文で使用。
	t_syntax_node	**children; // 子構文の配列。null-terminated。非終端構文で使用。
	int				start_pos; // 構文が始まるトークンのpos
	int				end_pos; // 対象外だったトークンのpos
}	t_syntax_node;

typedef struct s_lsa_list {
	t_lsa_list_type type;
	// pipelineとcompound_listのどちらかにしか入らない。
	// 片方がNULLならもう片方はnon-NULL。
	t_lsa_pipeline *pipeline;	// パイプライン
	t_lsa_list **compound_list; // NULL終端の配列
}	t_lsa_list;
```