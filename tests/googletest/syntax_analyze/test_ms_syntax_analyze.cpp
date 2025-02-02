#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

void ms_lexical_analyze_destroy_token_wrapper(void *token);
void test_runnner_of_syntax_analyze_fail(
	const char *str,
	const int pos
);

void test_runner_of_validate_check(
	const char *str,
	bool status
);

TEST(Syntax_Analyze, SUCCESS_CASE)
{
	t_token **tokens = ms_lexical_analyze("test");
	t_syntax_node *node = ms_syntax_analyze(tokens);
	EXPECT_EQ(node->type, SY_INSTRUCTION);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 1);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

TEST(Syntax_Analyze, VALIDATE_CHECK_TRUE)
{
	const char *str[] = {
		// single
		"\"\"", "\'\'", "\"test\"", "\'test\'", "="
		// out of space(list)
		" test", "test ", " test ",
		// pipe
		"test | test", "test| test", "test |test", "test|test","test|test ",
		// redirect
		"test > file", "test> file", "test >file", "test>file","test>file "
		// list
		"test || test", "test|| test", "test ||test",
		// compound_list
		"(test)", "( test)", "(test )", "( test )",
		// compound_list_list
		"(test) || (test)", "(test)|| (test)", "(test) ||(test)",
		// // compound_list_pipe
		// "(test) | (test)", "(test)| (test)", "(test) |(test)", "(test)|(test)",
		// // compound_list_redirect
		// "(test) > file", "(test)> file", "(test) >file", "(test)>file",
		// assignment
		"test=word", "test=word echo", "echo test=word",
		// variable
		"$hoge", "$hoge=value", "echo $hoge", "$hoge==value", "$hoge=value ",
		nullptr
	};

	for (int i = 0; str[i]; i++)
		test_runner_of_validate_check(str[i], true);
}

TEST(Syntax_Analyze, VALIDATE_CHECK_FALSE)
{
	const char *str[] = {
		// pipe
		"test|", "test |", "|test", "| test","test| |test",
		// redirect
		"test>", ">>>>test", "<>test",">test ||",">",">()>>",
		nullptr
	};

	for (int i = 0; str[i]; i++)
		test_runner_of_validate_check(str[i], false);
}
// not_quoted
TEST(Syntax_Analyze, FAIL_CASE_1)
{
	const char *str = "test >";
	test_runnner_of_syntax_analyze_fail(str, 2);
}
	

TEST(Syntax_Analyze, FAIL_CASE_2)
{
	const char *str = "test >>";
	test_runnner_of_syntax_analyze_fail(str, 2);
}

TEST(Syntax_Analyze, FAIL_CASE_3)
{
	const char *str = "test )";
	test_runnner_of_syntax_analyze_fail(str, 2);
}

void test_runnner_of_syntax_analyze_fail(
	const char *str,
	const int pos
)
{
	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *node = ms_syntax_analyze(tokens);
	EXPECT_EQ(node->type, SY_DECLINED);
	EXPECT_EQ(node->start_pos, pos);
	EXPECT_EQ(node->end_pos, pos  + 1);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

void test_runner_of_validate_check(
	const char *str,
	bool status
)
{
	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *node = ms_syntax_analyze(tokens);
	if (status)
		EXPECT_NE(node->type, SY_DECLINED) << "\"" << str << "\"";
	else
		EXPECT_EQ(node->type, SY_DECLINED) << "\"" << str << "\"";
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}
