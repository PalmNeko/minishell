 # ms_execution

 # 宣言
 ```c
 int ms_execution(const char *input);
 ```

 # 引数
 - **input**: 標準入力から入力され、履歴に登録されたコマンド文字列。

 # 説明
 構文解析を行いコマンドを実行する。
 この関数は複数の関数を再帰的に呼んでおり、以下に実行順を示す。
 基本的に、一つ前の戻り値が、次の関数の引数となるような設計となっている。
 1. ms_lexical_analyze
 1. ms_syntax_analyze
 1. ms_semantic_analyze
 1. ms_execute_from_lsa

 ms_execute_from_lsaに行くまでに、失敗した場合は、適切にエラーメッセージを出力して、終了する。

 ms_execute_from_lsaまで行った場合は、その戻り値を返す。

 # 戻り値
 - **成功時**: ms_execute_from_lsaの戻り値
 - **エラー時**: 適切にエラーメッセージを出力して終了
