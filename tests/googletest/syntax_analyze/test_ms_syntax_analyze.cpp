#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

void ms_lexical_analyze_destroy_token_wrapper(void *token);

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

TEST(Syntax_Analyze, FAIL_CASE_1)
{
	t_token **tokens = ms_lexical_analyze("\");");
	t_syntax_node *node = ms_syntax_analyze(tokens);
	EXPECT_EQ(node->type, SY_DECLINED);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 1);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}