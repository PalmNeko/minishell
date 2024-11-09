# 変数展開ヒアドクtoken_type設定
# 宣言
`void ms_set_heredoc_variable_expansion(t_list *tokens)`

# 説明
tokensのヒアドクのタイプのうち、そのトークンの次に現れる`TK_DELIMITER`以外の連続したトークンにシングルクォート、ダブルクォートが含まれているヒアドクのタイプに対して、`is_expansion`変数に`false`を設定する。

以下の挙動についてのフラグである。
> `cat << EOF""` -> ヒアドクで入力された文字列に対して変数展開されない。
> `cat << EOF` -> 変数展開される。
# 戻り値
なし

# エラー
なし
