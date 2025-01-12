#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

void test_runner_of_ms_parse(t_syntax_node *expect, const char *str, t_syntax_node *actual);

void ms_lexical_analyze_destroy_token_wrapper(void *token);

//----------------------------------------
// SY_WORD_LIST の成功パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_WordList, SY_WORDLIST_SUCCESS)
{
    const char *str = "\"word\"\"word\"";

    // 期待値用トークンを作る
    t_token **expect_tokens = ms_lexical_analyze(str);

    // 期待ノードの子配列
    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_double_quoted_word(expect_tokens, 0);
	expect_children[1] = ms_parse_double_quoted_word(expect_tokens, 3);
	expect_children[2] = NULL;


	// 期待ノード本体 (SY_WORD_LIST)
	t_syntax_node *expect = ms_syntax_node_create(SY_WORD_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 6;

    // 実際のパース結果
    t_syntax_node *actual = ms_parse_word_list(expect_tokens, 0);

    // 比較
    test_runner_of_ms_parse(expect, str, actual);

    // 後片付け
    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}