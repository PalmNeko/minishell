# 実行タスクの作成
# 宣言
`t_task	*ms_parsing(const char *input, t_error *error)`

# 説明

入力を処理し、コマンド実行しやすい形に変換する。
適宜エラーメッセージも出力する。
`syntax_error`などが起こった場合は、`error`構造体を書き書き換える。

# 戻り値

成功時、
エラー時、NULLを返す。
通常のエラーの時は、errorに値が設定される。
特に、致命的なエラーの時、errnoに適切な値が設定される。

# 通常のエラー

> **ここのエラーに関しては要相談**

syntax_error 構文エラー

# 致命的なエラー

ENOMEM malloc関連のエラー

# 構造体

```c
typedef enum e_error_type {
	E_SYNTAX_ERROR,
}	t_error_type;

typedef struct s_error {
	t_error type;
	char *message;
}	t_error;
```
