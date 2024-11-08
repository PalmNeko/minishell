# 変数展開

# 宣言
`t_list	*ms_parameter_expansion(const t_list *tokens, char *const envp[])`

# 説明
トークンのリスト(tokens)から、typeが`TK_VARIABLE`のものに対して、envpを使用して変数展開を行い、typeを`TK_WORD`に置き換える。

シングルクォートに対して変数展開を行わないために、`remove_single_quote`関数を呼ぶ必要がある。

envpがNULLの時は、`getenv`関数を使用して変数展開を行う。

tokensの中身は変更しない。

# 戻り値
成功時、t_token型の値をもつt_list型のリストを返す。
エラー時、NULLを返す。

# エラー
ENOMEM メモリ不足
