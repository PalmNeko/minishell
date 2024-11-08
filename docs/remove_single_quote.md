
# 宣言
`t_list	*ms_remove_single_quote(const t_list *tokens)`

# 説明
シングルクォートで囲まれているトークンを文字列として結合して、typeが`TK_WORD`のトークンで置き換えたものを新しく生成する。

変数展開に対応するために、事前に`parameter_expansion`関数を呼ぶ必要がある。

tokensの中身は変更しない。

# 戻り値
成功時、t_token型の値をもつt_list型のリストを返す。
エラー時、NULLを返す。

# エラー
ENOMEM メモリ不足
