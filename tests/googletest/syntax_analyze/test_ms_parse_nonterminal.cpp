#include <gtest/gtest.h>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

void test_runner_of_ms_parse(t_syntax_node *expect, const char *str, t_syntax_node *actual);
void ms_lexical_analyze_destroy_token_wrapper(void *token);

//----------------------------------------
// SY_DOUBLE_QUOTED_WORD の成功パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_DOUBLE_QUOTED_WORD_SUCCESS)
{
    const char *str = "\"word\"";

    // 期待値用トークンを作る
    t_token **expect_tokens = ms_lexical_analyze(str);

    // 期待ノードの子配列
    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_double_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_double_quote(expect_tokens, 2);
	expect_children[3] = NULL;

    // 期待ノード本体 (SY_DOUBLE_QUOTED_WORD)
    t_syntax_node *expect = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD);
    expect->children  = expect_children;
    expect->start_pos = 0;
    expect->end_pos   = 3;

    // 実際のパース結果
    t_syntax_node *actual = ms_parse_double_quoted_word(expect_tokens, 0);

    // 比較
    test_runner_of_ms_parse(expect, str, actual);

    // 後片付け
    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}

//----------------------------------------
// SY_DOUBLE_QUOTED_WORD の失敗パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_DOUBLE_QUOTED_WORD_FAIL)
{
    const char *str = "\"word"; // 終了ダブルクォートがない

    // 実際の解析結果
    t_token **tokens = ms_lexical_analyze(str);
    t_syntax_node *actual = ms_parse_double_quoted_word(tokens, 0);

    // 期待ノード (SY_DECLINED)
    t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
    // “どのトークンで失敗したか” の情報を持たせるなら、以下のように
    expect->token = tokens[0];
    expect->start_pos = 0;
    expect->end_pos   = 1; 

    // 比較
    test_runner_of_ms_parse(expect, str, actual);

    // 後片付け
    ms_syntax_node_destroy(expect);
    // actual は test_runner 内で破棄済み
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

//SY_SINGLE_QUOTED_WORD の成功パターン

TEST(Syntax_Analyze_Parse_Nonterminal, SY_SINGLE_QUOTED_WORD_SUCCESS)
{
	const char *str = "'word'";

	// 期待値用トークンを作る
	t_token **expect_tokens = ms_lexical_analyze(str);

	// 期待ノードの子配列
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_single_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_single_quote(expect_tokens, 2);
	expect_children[3] = NULL;

	// 期待ノード本体 (SY_SINGLE_QUOTED_WORD)
	t_syntax_node *expect = ms_syntax_node_create(SY_SINGLE_QUOTED_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	// 実際のパース結果
	t_syntax_node *actual = ms_parse_single_quoted_word(expect_tokens, 0);

	// 比較
	test_runner_of_ms_parse(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2(reinterpret_cast<void**>(expect_tokens), ms_lexical_analyze_destroy_token_wrapper);
}

//SY_SINGLE_QUOTED_WORD の失敗パターン
TEST(Syntax_Analyze_Parse_Nonterminal, SY_SINGLE_QUOTED_WORD_FAIL)
{
	const char *str = "'word"; // 終了シングルクォートがない

	// 実際の解析結果
	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_single_quoted_word(tokens, 0);

	// 期待ノード (SY_DECLINED)
	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	// “どのトークンで失敗したか” の情報を持たせるなら、以下のように
	expect->token = tokens[0];
	expect->start_pos = 0;
	expect->end_pos   = 1; 

	// 比較
	test_runner_of_ms_parse(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	// actual は test_runner 内で破棄済み
	ms_destroy_ntp2(reinterpret_cast<void**>(tokens), ms_lexical_analyze_destroy_token_wrapper);
}


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

	// "word word" という文字列を解析する
	// 期待値用トークンを作る
	t_token **expect_tokens2 = ms_lexical_analyze("word ");

	// 期待ノードの子配列
	t_syntax_node **expect_children2 = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children2[0] = ms_parse_identify(expect_tokens2, 0);
	expect_children2[1] = NULL;

	// 期待ノード本体 (SY_WORD_LIST)
	t_syntax_node *expect2 = ms_syntax_node_create(SY_WORD_LIST);
	expect2->children  = expect_children2;
	expect2->start_pos = 0;
	expect2->end_pos   = 1;

	// 実際のパース結果
	t_syntax_node *actual2 = ms_parse_word_list(expect_tokens2, 0);

	// 比較
	test_runner_of_ms_parse(expect2, "word ", actual2);

	// 後片付け
	ms_syntax_node_destroy(expect2);
	ms_destroy_ntp2((void**)expect_tokens2, ms_lexical_analyze_destroy_token_wrapper);
}

// FAILED

TEST(Syntax_Analyze_Parse_WordList, SY_WORDLIST_FAIL)
{ 
	const char *str = " ";
	// 実際の解析結果
	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_word_list(tokens, 0);

	// 期待ノード (SY_DECLINED)
	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	// “どのトークンで失敗したか” の情報を持たせるなら、以下のように
	expect->token = tokens[0];
	expect->start_pos = 0;
	expect->end_pos   = 1; 

	// 比較
	test_runner_of_ms_parse(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	// actual は test_runner 内で破棄済み
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

// SY_ASSIGNMENT_WORD
TEST(Syntax_Analyze_Parse_Nonterminal, SY_ASSIGNMENT_WORD_SUCCESS)
{
	const char *str = "test=word";

	// create expect tokens
	t_token **expect_tokens = ms_lexical_analyze(str);

	// children of expect node
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_identify(expect_tokens, 0);
	expect_children[1] = ms_parse_equal(expect_tokens, 1);
	expect_children[2] = ms_parse_word_list(expect_tokens, 2);
	expect_children[3] = NULL;

	// expect body of node
	t_syntax_node *expect = ms_syntax_node_create(SY_ASSIGNMENT_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	// actual node
	t_syntax_node *actual = ms_parse_assignment_word(expect_tokens, 0);

	// compare
	test_runner_of_ms_parse(expect, str, actual);

	// clean up
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}

// SY_REDIRECTION_WORD
TEST(Syntax_Analyze_Parse_Nonterminal, SY_REDIRECTION_WORD_SUCCESS)
{
	const char *str = ">> word";

	// create expect tokens
	t_token **expect_tokens = ms_lexical_analyze(str);

	// children of expect node
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_redirection(expect_tokens, 0);
	expect_children[1] = ms_parse_blank(expect_tokens, 1);
	expect_children[2] = ms_parse_word_list(expect_tokens, 2);
	expect_children[3] = NULL;

	// expect body of node
	t_syntax_node *expect = ms_syntax_node_create(SY_REDIRECTION_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	// actual node
	t_syntax_node *actual = ms_parse_redirection_word(expect_tokens, 0);

	// compare
	test_runner_of_ms_parse(expect, str, actual);

	// clean up
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}

// SY_SIMPLE_COMMAND
TEST(Syntax_Analyze_Parse_Nonterminal, SY_SIMPLE_COMMAND_SUCCESS)
{
	const char *str = "test    word";

	// create expect tokens
	t_token **expect_tokens = ms_lexical_analyze(str);

	// children of expect node
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_word_list(expect_tokens, 0);
	expect_children[1] = ms_parse_blank(expect_tokens, 1);
	expect_children[2] = ms_parse_word_list(expect_tokens, 2);
	expect_children[3] = NULL;

	// expect body of node
	t_syntax_node *expect = ms_syntax_node_create(SY_SIMPLE_COMMAND);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	// actual node
	t_syntax_node *actual = ms_parse_simple_command(expect_tokens, 0);

	// compare
	test_runner_of_ms_parse(expect, str, actual);

	// clean up
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}