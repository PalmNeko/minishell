 # 展開
 ## 一覧
 | 関数名 | 説明 |
 | --- | --- |
 | ms_expansion | 展開処理 |
 | ms_tilde_expansion | チルダ展開 |
 | ms_parameter_expansion | パラメータと変数の展開 |
 | ms_pathname_expansion | パス名展開 |
 | ms_quote_removal | クォート削除 |
 | ms_syntax_node_to_word_node | 非終端ノードを結合して一つの`SY_WORD`ノードに変換する |
 | ms_wildcard_pathname | パスからワイルドカードに合うファイル・ディレクトリを抜き出す |
 | ms_wildcard_pathname_recursive | パターンに合うファイル・ディレクトリを抜き出す |
 | ms_much_pattern | 文字列がパターンに一致するかを判定する |
 | ms_split_syntax_node | 構文ノードを特定のタイプのノードで分割する |
 | ms_syntax_node_ntp_to_string | NULL終端配列の構文ノードを文字列に変換する |

 ## ms_expansion
 - **宣言**:
 ```c
 char **ms_expansion(t_lsa_word_list *word_list);
 ```
 - **説明**:
	この展開処理は以下の処理を順に行った結果となる。
	1. チルダ展開 ms_tilde_expansion
	1. パラメータ・ 変数展開 ms_parameter_expansion
	1. パス名展開 ms_pathname_expansion
	1. クォートの削除 ms_quote_removal

	最後に、t_syntax_nodeを`SY_BLANK`で分割して、t_syntax_nodeを文字列に変換したものを戻り値とする。

 - **引数**:
	 - **word_list**: 区切り文字の含まないクォートや変数参照の含まれるデータ
 - **戻り値**
	 - **成功時**: 複製された情報へのポインタ
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_tilde_expansion
 - **宣言**:
 ```c
 t_syntax_node *ms_tilde_expansion(t_syntax_node *word_list);
 ```
 - **説明**:
	 - チルダ展開を行い、新しいsyntax_nodeを返す。
	 - クォートされていないチルダ`~`が先頭にあり、`/`以外の文字列が続かないとき、HOME変数に書き換える。
	 - HOMEがないときは、空文字列に書き換える。
	 - 書き換えた文字列は、シングルクォートで囲まれたものと同じように扱う。`SY_SINGLE_QUOTED_WORD`
 - **引数**:
	 - **word_list**: SY_WORD_LISTの構文ノード `SY_WORD_LIST`
 - **戻り値**
	 - **成功時**: 作成された構文ノードへのポインタ `SY_WORD_LIST`
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_parameter_expansion
 - **宣言**:
 ```c
 t_syntax_node *ms_parameter_expansion(t_syntax_node *word_list);
 ```
 - **説明**:
	 - シングルクォートでクォートされていない変数 `SY_VARIABLE` に対して、変数展開を行い、 `SY_WORD` として置き換える。
	 - 新しい構文ノード `SY_WORD_LIST` を返す。
 - **引数**:
	 - **word_list**: `SY_WORD_LIST`の構文ノード。
 - **戻り値**
	 - **成功時**: 複製された情報へのポインタ
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_pathname_expansion
 - **宣言**:
 ```c
 t_syntax_node *ms_pathname_expansion(t_syntax_node *word_list);
 ```
 - **説明**:
	 - 引数のword_listのうち、`SY_WORD`に`*`が含まれている場合、パス名展開を行う。含まれていない場合や１つも見つからなかった場合はそのまま返す。パス名展開は次の手順んで行う。
	 	 1. word_listを文字列に変換し、結合する。
			> クォート内は、`*`はワイルドカードではなく文字として扱う。
			> ワイルドカードと文字としての`*`を区別するために、クォートすること。
			> クォート用と文字としての`\`を区別するためにクォートすること。
		 1. 文字列に `ms_expand_pathname` を使って、パス展開を行う。
		 1. 空白区切りで、ファイル名・ディレクトリ名を結合した`SY_WORD_LIST` を作成する。各ファイルは`SY_WORD`、空白は `SY_BLANK` として作成する。
 - **引数**:
	 - **word_list**: `SY_WORD_LIST`の構文ノード
 - **戻り値**
	 - **成功時**: NULL終端の配列。
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_quote_removal
 - **宣言**:
 ```c
 t_syntax_node *ms_quote_removal(t_syntax_node *word_list);
 ```
 - **説明**:
	 - `SY_SINGLE_QUOTED_WORD` `SY_DOUBLE_QUOTED_WORD`を展開し、`SY_WORD`として追加する。
 - **引数**:
 - **戻り値**
	 - **成功時**: 複製された情報へのポインタ
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_syntax_node_to_word_node
 - **宣言**:
 ```c
 t_syntax_node *ms_syntax_node_to_word_node(t_syntax_node *node)
 ```
 - **説明**:
	 - node以下を再帰的にchildrenを探索し、非終端ノードを結合し、新しい構文ノード `SY_WORD` を生成する。
	 > ms_quote_removalやt_syntax_nodeの実装で使うはず。
 - **引数**:
	 - **node**: 構文ノード
 - **戻り値**
	 - **成功時**: 構文ノード `SY_WORD` へのポインタ
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー


 ## ms_wildcard_pathname
 - **宣言**:
 ```c
 char **ms_wildcard_pathname(const char *path, const char *pattern);
 ```
 - **説明**:
	 - pathから、パターンに一致するファイル・ディレクトリを検索する。
	 - `\`の後の文字はそのままの意味として解釈する。
	 - `*`はワイルドカードとして動作し、任意の文字列に一致する。
 - **引数**:
	 - **path**: 対象のディレクトリ（相対 or 絶対）
	 - **pattern**: 検索するパターン
 - **戻り値**
	 - **成功時**: NULL終端の文字列。path + 見つかったファイル・ディレクトリ名
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_wildcard_pathname_recursive
 - **宣言**:
 ```c
 char **ms_wildcard_pathname_recursive(const char *pattern)
 ```
 - **説明**:
	 - patternを元に、複数のワイルドカードを再帰的に検索する。
	 > クォート`\`に注意すること。
	 > ms_wildcard_pathname関数を参照
	 > 説明が難しいです。
 - **引数**:
	 - **pattern**: `/tmp/*`や `*`, `\*sam*`など様々な形式で渡される。
 - **戻り値**
	 - **成功時**: NULL終端の文字列。
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_much_pattern
 - **宣言**:
 ```c
 bool ms_much_pattern(const char *text, const char *pattern);
 ```
 - **説明**:
	 - textがpatternで表される文字列かどうかを判定する。
 - **引数**:
	 - **text**: 判定する文字列
	 - **pattern**: パターン文字列
 - **戻り値**
	 - **true**: 一致するとき
	 - **false**: 一致しないとき


 ## ms_split_syntax_node
 - **宣言**:
 ```c
 t_syntax_node **ms_split_syntax_node(t_syntax_node *node, t_syntax_type sep);
 ```
 - **説明**:
	 - sepの種類のノードでノードを分割する。
	 - 戻り値のsyntax_node_typeはnodeのタイプを継承する。
 - **引数**:
	 - **node**: 構文ノード
	 - **sep**: 分割に使用する構文のタイプ
 - **戻り値**
	 - **成功時**: NULL終端の配列
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー

 ## ms_syntax_node_ntp_to_string
 - **宣言**:
 ```c
 char **ms_syntax_node_ntp_to_string(t_syntax_node **nodes);
 ```
 - **説明**:
	 - nodesの各要素を、文字列に変換する。メモリに配置すること。
 - **引数**:
	 - **nodes**: NULL終端の配列の構文ノード
 - **戻り値**
	 - **成功時**: NULL終端の配列の文字列
	 - **失敗時**: NULL
 - **エラー**:
	 - **ENOMEM**: malloc関連のエラー
