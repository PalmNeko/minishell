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