# 実行タスクの作成
# 宣言
`t_task	*generate_execution_task(t_syntax_node *root)`

# 説明
構文木から実行のための情報を作成する。

> 環境変数の代入式になる部分は、最初の`SY_MERGED_WORD`までの`SY_ASSIGNMENT_WORD`が対象である。

# 戻り値
成功時、実行タスク
失敗時、NULLを返し、適切なerrnoを設定する。

# エラー
ENOMEM malloc関連のエラー

# 構造体

```c
typedef t_pipeline	t_task;

typedef struct s_pipeline {
	t_simple_command **commands; // コマンドの配列
}	t_pipeline;

typedef t_command {
	char 			**arguments; // 引数の配列
	t_redirection	**redirects; // リダイレクションの配列
	t_assignment	**assignments; // 環境変数代入の配列
}

typedef s_redirection {
	t_redirection_type type; // リダイレクションの型
	int	target_fd; // リダイレクト先のfd
	bool heredoc_variable_expansion; // ヒアドクで読み取る際に変数展開するかどうか。
	char *filename; // ファイル名 or delimiter
}	t_redirection;

typedef s_assignment {
	char *name; // 変数名
	char *value; // 値
}	t_assignment;
```
