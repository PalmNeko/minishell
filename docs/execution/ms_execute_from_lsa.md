 # コマンドの実行
 # 宣言

```c
int	ms_execute_from_lsa(t_lsa *lsa);
```
 # 引数

 # 説明
 - 意味解析が終わった後にこの関数は実行される。
 - 各関数は次の順に階層的に呼び出され、適切にコマンドを実行する。
 	1. ms_execute_list
		1. ms_execute_pipeline
			1. ms_simple_command_execution

 # 戻り値
 -
 # エラー

 # 構造体

 # 関数
 ## 一覧
 | 関数名 | 説明 |
 | --- | --- |
 | ms_execute_list | リストの実行 |
 | ms_execute_lists | 複数のリストの実行 |
 | ms_execute_compound_lists | 複合リストの実行 |
 | ms_execute_pipeline | パイプラインの実行 |
 | ms_simple_command_execution | コマンドの実行 (別ファイル) |

 ## ms_execute_list
 - **宣言**:
 ```c
 int ms_execute_list(t_lsa_list *list);
 ```
 - **説明**:
	 - list->typeの値によって、終了ステータスを確認して、条件に合えば、pipelineもしくはcompound_listを実行する。
	 - pipelineがNULLでなければ、pipelineを、compound_listがNULL出なければ、compound_listを再帰的に順次実行する。
	 - compound_listを実行するときは、`ms_execute_compound_lists`を呼び出し実行する。

	 | type | 条件 |
	 | --- | --- |
	 | LSA_LIST_ALWAYS | 常に実行する |
	 | LSA_LIST_AND | 終了ステータスが0だった時に実行 |
	 | LSA_LIST_OR | 終了ステータスが0以外だった時に実行 |
 - **引数**:
	 - **list**: 実行するリスト。
 - **戻り値**
	 - **成功時**: 終了ステータスを返す。
	 - **失敗時**: -1
 - **エラー**:
	 - **ENOMEM**: mallocやfork, pipe, dupのエラー

 ## ms_execute_lists
 - **宣言**:
 ```c
 int ms_execute_lists(t_lsa_list **lists)
 ```
 - **説明**:
	 - 順に複数のリストを実行する。
 - **引数**:
	 - **lists**: 複数のリスト
 - **戻り値**
	 - **成功時**: すべてリストを実行し終わった時点の終了ステータス
	 - **エラー時**: -1
 - **エラー**: mallocやfork, pipe, dupのエラー

 ## ms_execute_compound_lists
 - **宣言**:
 ```c
 int ms_execute_compound_lists(t_lsa_list **lists)
 ```
 - **説明**:
	 - 複合リストを実行する。
	 - 実行するときは、forkしサブシェル内として実行すること。
 - **引数**:
	 - **lists**: 実行する複数のリスト
 - **戻り値**
	 - **成功時**: すべてリストを実行し終わった時点の終了ステータス
	 - **エラー時**: -1
 - **エラー**: mallocやfork, pipe, dupのエラー

 ## ms_execute_pipeline
 - **宣言**:
 ```c
 int ms_execute_pipeline(t_lsa_pipeline *pipeline);
 ```
 - **説明**:
	 - 連続したコマンドの入出力をpipeした環境で、各単純コマンドを実行する。
 - **引数**:
 - **戻り値**
	 - **成功時**: 最後に実行した単純コマンドの終了ステータス
	 - **失敗時**: -1
 - **エラー**:
	 - **ENOMEM**: mallocやfork, pipe, dupのエラー

 ## ms_simple_command_execution
 - ms_simple_command.mdで設計されています。
