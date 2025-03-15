#include <gtest/gtest.h>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
};

void test_runner_of_ms_parse(t_syntax_node *expect, const char *str, t_syntax_node *actual);
void ms_destroy_token_wrapper(void *token);

//----------------------------------------
// SY_DOUBLE_QUOTED_WORD
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_DOUBLE_QUOTED_WORD_SUCCESS)
{
    const char *str = "\"word\"";

    t_token **expect_tokens = ms_lexical_analyze(str);

    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_double_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_double_quote(expect_tokens, 2);
	expect_children[3] = NULL;

    t_syntax_node *expect = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD);
    expect->children  = expect_children;
    expect->start_pos = 0;
    expect->end_pos   = 3;

    t_syntax_node *actual = ms_parse_double_quoted_word(expect_tokens, 0);

    test_runner_of_ms_parse(expect, str, actual);

    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_DOUBLE_QUOTED_WORD_SUCCESS2)
{
    const char *str = "\"\"";

    t_token **expect_tokens = ms_lexical_analyze(str);

    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_double_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_double_quote(expect_tokens, 1);
	expect_children[2] = NULL;

    t_syntax_node *expect = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD);
    expect->children  = expect_children;
    expect->start_pos = 0;
    expect->end_pos   = 2;

    t_syntax_node *actual = ms_parse_double_quoted_word(expect_tokens, 0);

    test_runner_of_ms_parse(expect, str, actual);

    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}


TEST(Syntax_Analyze_Parse_Nonterminal, SY_DOUBLE_QUOTED_WORD_FAIL)
{
    const char *str = "\"word"; // 終了ダブルクォートがない

    t_token **tokens = ms_lexical_analyze(str);
    t_syntax_node *actual = ms_parse_double_quoted_word(tokens, 0);

    t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);

    expect->token = ms_duplicate_token(tokens[0]);
    expect->start_pos = 0;
    expect->end_pos   = 1; 

    test_runner_of_ms_parse(expect, str, actual);

    ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_SINGLE_QUOTED_WORD
//----------------------------------------

TEST(Syntax_Analyze_Parse_Nonterminal, SY_SINGLE_QUOTED_WORD_SUCCESS)
{
	const char *str = "'word'";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_single_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_single_quote(expect_tokens, 2);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_SINGLE_QUOTED_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_single_quoted_word(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2(reinterpret_cast<void**>(expect_tokens),  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_SINGLE_QUOTED_WORD_FAIL)
{
	const char *str = "'word"; // 終了シングルクォートがない

	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_single_quoted_word(tokens, 0);

	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1; 

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2(reinterpret_cast<void**>(tokens),  ms_destroy_token_wrapper);
}


//----------------------------------------
// SY_WORD_LIST の成功パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_WORDLIST_SUCCESS)
{
    const char *str = "$hoge\"word\"!test\'word\'hoge";

    t_token **expect_tokens = ms_lexical_analyze(str);

    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 6);
	expect_children[0] = ms_parse_variable(expect_tokens, 0);
	expect_children[1] = ms_parse_double_quoted_word(expect_tokens, 1);
	expect_children[2] = ms_parse_word(expect_tokens, 4);
	expect_children[3] = ms_parse_single_quoted_word(expect_tokens, 5);
	expect_children[4] = ms_parse_identify(expect_tokens, 8);
	expect_children[5] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_WORD_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 9;

    t_syntax_node *actual = ms_parse_word_list(expect_tokens, 0);

    test_runner_of_ms_parse(expect, str, actual);

    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);

	t_token **expect_tokens2 = ms_lexical_analyze("word |");

	t_syntax_node **expect_children2 = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children2[0] = ms_parse_identify(expect_tokens2, 0);
	expect_children2[1] = NULL;

	t_syntax_node *expect2 = ms_syntax_node_create(SY_WORD_LIST);
	expect2->children  = expect_children2;
	expect2->start_pos = 0;
	expect2->end_pos   = 1;

	t_syntax_node *actual2 = ms_parse_word_list(expect_tokens2, 0);

	test_runner_of_ms_parse(expect2, "word ", actual2);

	ms_syntax_node_destroy(expect2);
	ms_destroy_ntp2((void**)expect_tokens2,  ms_destroy_token_wrapper);
}

// FAILED

TEST(Syntax_Analyze_Parse_Nonterminal, SY_WORDLIST_FAIL_CASE_1)
{ 
	const char *str = "\"word";

	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_word_list(tokens, 0);

	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1; 

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_WORDLIST_FAIL_CASE_2)
{
	const char *str = "\"word"; // 終了ダブルクォートがない

	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_word_list(tokens, 0);

	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1;

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}


// SY_ASSIGNMENT_WORD(variable name part)
TEST(Syntax_Analyze_Parse_Nonterminal, SY_ASSIGNMENT_WORD_name_SUCCESS)
{
	const char *str = "test=word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[0] = ms_parse_identify(expect_tokens, 0);
	expect_children[1] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_WORD_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 1;

	t_syntax_node *actual = ms_parse_assignment_word_name(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// SY_ASSIGNMENT_WORD
TEST(Syntax_Analyze_Parse_Nonterminal, SY_ASSIGNMENT_WORD_SUCCESS)
{
	const char *str = "test=word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_assignment_word_name(expect_tokens, 0);
	expect_children[1] = ms_parse_equal(expect_tokens, 1);
	expect_children[2] = ms_parse_word_list(expect_tokens, 2);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_ASSIGNMENT_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_assignment_word(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// SY_REDIRECTION_WORD
TEST(Syntax_Analyze_Parse_Nonterminal, SY_REDIRECTION_WORD_SUCCESS)
{
	const char *str = ">> word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_redirection(expect_tokens, 0);
	expect_children[1] = ms_parse_word_list(expect_tokens, 2);
	expect_children[2] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_REDIRECTION_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_redirection_word(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_REDIRECTION_WORD_SUCCESS3)
{
	const char *str = ">>word>word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_redirection(expect_tokens, 2);
	expect_children[1] = ms_parse_word_list(expect_tokens, 3);
	expect_children[2] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_REDIRECTION_WORD);
	expect->children  = expect_children;
	expect->start_pos = 2;
	expect->end_pos   = 4;

	t_syntax_node *actual = ms_parse_redirection_word(expect_tokens, 2);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_REDIRECTION_WORD_FAIL)
{
	const char *str = ">";

	t_token **tokens = ms_lexical_analyze(str);

	t_syntax_node *actual = ms_parse_pipeline(tokens, 0);

	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1;

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_SIMPLE_COMMAND
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_SIMPLE_COMMAND_SUCCESS)
{
	const char *str = "test    word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_word_list(expect_tokens, 0);
	expect_children[1] = ms_parse_word_list(expect_tokens, 2);
	expect_children[2] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_SIMPLE_COMMAND);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_simple_command(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);

	const char *str2 = "test | word";

	t_token **expect_tokens2 = ms_lexical_analyze(str2);

	t_syntax_node **expect_children2 = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children2[0] = ms_parse_word_list(expect_tokens2, 0);
	expect_children2[1] = NULL;

	// expect body of node
	t_syntax_node *expect2 = ms_syntax_node_create(SY_SIMPLE_COMMAND);
	expect2->children  = expect_children2;
	expect2->start_pos = 0;
	expect2->end_pos   = 1;

	// actual node
	t_syntax_node *actual2 = ms_parse_simple_command(expect_tokens2, 0);

	// compare
	test_runner_of_ms_parse(expect2, str2, actual2);

	// clean up
	ms_syntax_node_destroy(expect2);
	ms_destroy_ntp2((void**)expect_tokens2,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_SIMPLE_COMMAND_SUCCESS2)
{
	const char *str = "test > word >> word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_word_list(expect_tokens, 0);
	expect_children[1] = ms_parse_redirection_word(expect_tokens, 2);
	expect_children[2] = ms_parse_redirection_word(expect_tokens, 6);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_SIMPLE_COMMAND);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 9;

	t_syntax_node *actual = ms_parse_simple_command(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_ASSIGNMENT_COMMAND
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_ASSIGNMENT_COMMAND_SUCCESS)
{
	const char *str = "test=word test2=word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_assignment_word(expect_tokens, 0);
	expect_children[1] = ms_parse_assignment_word(expect_tokens, 4);
	expect_children[2] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_ASSIGNMENT_COMMAND);

	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 7;
	
	t_syntax_node *actual = ms_parse_assignment_command(expect_tokens, 0);
	
	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_COMMAND
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_COMMAND_SUCCESS)
{
	const char *str = "test | word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[0] = ms_parse_simple_command(expect_tokens, 0);
	expect_children[1] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_COMMAND);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 1;

	t_syntax_node *actual = ms_parse_command(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);

	const char *str2 = "test=word";

	t_token **expect_tokens2 = ms_lexical_analyze(str2);

	t_syntax_node **expect_children2 = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children2[0] = ms_parse_assignment_command(expect_tokens2, 0);
	expect_children2[1] = NULL;

	t_syntax_node *expect2 = ms_syntax_node_create(SY_COMMAND);
	expect2->children  = expect_children2;
	expect2->start_pos = 0;
	expect2->end_pos   = 3;
	
	t_syntax_node *actual2 = ms_parse_command(expect_tokens2, 0);

	test_runner_of_ms_parse(expect2, str2, actual2);

	ms_syntax_node_destroy(expect2);
	ms_destroy_ntp2((void**)expect_tokens2,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_PIPELINE
// (command)のケースにおいてNULLが帰ってくる潜在的なエラー有。
//----------------------------------------
TEST(Syntax_Analyze_Parse_Nonterminal, SY_PIPELINE_SUCCESS)
{
	const char *str = "test | word";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 6);
	expect_children[0] = ms_parse_command(expect_tokens, 0);
	expect_children[1] = ms_parse_pipe(expect_tokens, 2);
	expect_children[2] = ms_parse_command(expect_tokens, 4);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_PIPELINE);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 5;

	t_syntax_node *actual = ms_parse_pipeline(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// FAILED_CASE(DECLINEDが欲しい場合においてNULLを返してしまっている）
TEST(Syntax_Analyze_Parse_Nonterminal, SY_PIPELINE_FAIL)
{
	const char *str = "|";

	// 実際の解析結果
	t_token **tokens = ms_lexical_analyze(str);

	t_syntax_node *actual = ms_parse_pipeline(tokens, 0);

	// 期待ノード (SY_DECLINED)
	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1;

	// 比較
	test_runner_of_ms_parse(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_LIST
//----------------------------------------

// single list
TEST(Syntax_Analyze_Parse_Nonterminal, SY_LIST_SUCCESS_CASE1)
{
	const char *str = "test | word";

	// 期待値用トークンを作る
	t_token **expect_tokens = ms_lexical_analyze(str);

	// 期待ノードの子配列
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[0] = ms_parse_pipeline(expect_tokens, 0);
	expect_children[1] = NULL;
	

	// 期待ノード本体 (SY_LIST)
	t_syntax_node *expect = ms_syntax_node_create(SY_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 5;

	// 実際のパース結果
	t_syntax_node *actual = ms_parse_list(expect_tokens, 0);

	// 比較
	test_runner_of_ms_parse(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// multiple list
TEST(Syntax_Analyze_Parse_Nonterminal, SY_LIST_SUCCESS_CASE2)
{
	const char *str = "test | word || test2 | word2";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_pipeline(expect_tokens, 0);
	expect_children[1] = ms_parse_list_token(expect_tokens, 6);
	expect_children[2] = ms_parse_pipeline(expect_tokens, 7);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 13;

	t_syntax_node *actual = ms_parse_list(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

//----------------------------------------
// SY_COMPOUND_LIST
//----------------------------------------

TEST(Syntax_Analyze_Parse_Nonterminal, SY_COMPOUND_LIST_SUCCESS)
{
	const char *str = "(test | word)";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_left_parenthesis(expect_tokens, 0);
	expect_children[1] = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	expect_children[1]->type = SY_LIST;
	expect_children[1]->start_pos = 1;
	expect_children[1]->end_pos = 6;
	expect_children[1]->token = NULL;
	expect_children[1]->children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[1]->children[0] = ms_parse_pipeline(expect_tokens, 1);
	expect_children[1]->children[1] = NULL;
	expect_children[2] = ms_parse_right_parenthesis(expect_tokens, 6);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_COMPOUND_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 7;

	t_syntax_node *actual = ms_parse_compound_list(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// 閉じ忘れ
TEST(Syntax_Analyze_Parse_Nonterminal, SY_COMPOUND_LIST_FAIL)
{
	const char *str = "(test | word";

	t_token **tokens = ms_lexical_analyze(str);

	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	expect->token = ms_duplicate_token(tokens[0]);
	expect->start_pos = 0;
	expect->end_pos   = 1;

	t_syntax_node *actual = ms_parse_compound_list(tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}


// ----------------------------------------
// SY_LIST_WITH_COMPOND_LIST
// ----------------------------------------

TEST(Syntax_Analyze_Parse_Nonterminal, SY_LIST_WITH_COMPOUND_LIST_SUCCESS)
{
	const char *str = "(test | word)";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[0] = ms_parse_compound_list(expect_tokens, 0);
	expect_children[1] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_LIST);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 7;

	t_syntax_node *actual = ms_parse_list(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// ----------------------------------------
// SY_USER_INPUT
// ----------------------------------------

TEST(Syntax_Analyze_Parse_Nonterminal, SY_USER_INPUT_SUCCESS)
{
	const char *str = "ygtaa EOF";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_all(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_all(expect_tokens, 2);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_USER_INPUT);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_user_input(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

// ----------------------------------------
// SY_INSTURCTION
// ----------------------------------------

TEST(Syntax_Analyze_Parse_Nonterminal, SY_INSTRUCTION_SUCCESS_CASE1)
{
	const char *str = "echo hello";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 2);
	expect_children[0] = ms_parse_list(expect_tokens, 0);
	expect_children[1] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_INSTRUCTION);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	t_syntax_node *actual = ms_parse_instruction(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_INSTRUCTION_SUCCESS_CASE2)
{
	const char *str = "echo hello\n";

	t_token **expect_tokens = ms_lexical_analyze(str);

	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 3);
	expect_children[0] = ms_parse_list(expect_tokens, 0);
	expect_children[1] = ms_parse_newline(expect_tokens, 3);
	expect_children[2] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_INSTRUCTION);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 4;

	t_syntax_node *actual = ms_parse_instruction(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}

TEST(Syntax_Analyze_Parse_Nonterminal, SY_INSTRUCTION_SUCCESS_CASE3)
{
	const char *str = "input.txt << EOF\nhoge\nfuga\nEOF";

	t_token **expect_tokens = ms_lexical_analyze(str);
	
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_list(expect_tokens, 0);
	expect_children[1] = ms_parse_newline(expect_tokens, 5);
	expect_children[2] = ms_parse_user_input(expect_tokens, 6);
	expect_children[3] = NULL;

	t_syntax_node *expect = ms_syntax_node_create(SY_INSTRUCTION);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 11;

	t_syntax_node *actual = ms_parse_instruction(expect_tokens, 0);

	test_runner_of_ms_parse(expect, str, actual);

	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2((void**)expect_tokens,  ms_destroy_token_wrapper);
}