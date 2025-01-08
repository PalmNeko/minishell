#include <gtest/gtest.h>
#include <iostream>


extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "ms_test.h"
};

void ms_syntax_node_destroy(t_syntax_node *node);

TEST(Syntax_Analyze_Parse, SY_BLANK_single_token)
{
	t_token **tokens = ms_lexical_analyze(" ");
	t_syntax_node *node = ms_parse_blank(tokens[0], 0);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_BLANK);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 1);
	ms_syntax_node_destroy(node);
	ms_lexical_analyze_destroy_token(tokens[0]);
	free(tokens);
}
