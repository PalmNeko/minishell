設計をのBNFを一部修正を行いEBNFに書き換えました。

```
# 終端構文
<all> ::= 全ての種類のトークン

# クォート
<double_quoted_word> ::= <double_quote> <all>* <double_quote>
<single_quoted_word> ::= <single_quote> <all>* <single_quote>

# ワード
<word_list> ::= <word_item> { <word_item> }
<word_item> ::= <identify> | <word> | <double_quoted_word> | <single_quoted_word> | <variable> | <equal>

# コマンド
<command> ::= <command_head> {<blank>? <simple_command>}
<command_head> ::= <assignment_command> | <simple_command> 
<assignment_command> ::= <assignment_word> {<blank> <assignment_word>}
<assignment_word> ::= <identify> <equals> <word_list>
<simple_command> ::= <simple_command_item> {<blank>? <simple_command_item>}
<simple_command_item> ::= <word_list> | <redirection_word>
<redirection_word> ::= <redirection> <blank>? <word_list>

# パイプライン
<pipeline> ::= <blank>? <pipeline_item> <blank>? { <pipe> <blank>? <pipeline_item> <blank>?} 
<pipeline_item> = <command> | <compound_list>
<compound_list> ::= <blank>? <left_parenthesis> <list> <right_parenthesis> <blank>?

# リスト
<list> ::= <pipeline> {<list_token> <pipeline>} | <compound_list>

# 命令
<instruction>   ::= <list> { <newline> { <user_input> } }
<user_input> ::= <all> {<all>}
```