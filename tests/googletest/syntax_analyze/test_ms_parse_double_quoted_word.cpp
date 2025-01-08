#include <gtest/gtest.h>
#include <iostream>


extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "ms_test.h"
};

void ms_syntax_node_destroy(t_syntax_node *node);

TEST(Syntax_Analyze_Parse, SY_DOUBLE_QUOTED_WORD_SUCESS)
{
	t_token **tokens = ms_lexical_analyze("\"Hello\"");
	t_syntax_node *node = ms_parse_double_quoted_word(tokens, 0);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_DOUBLE_QUOTED_WORD);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 3);
	for(int i = 0; node->children[i]; i++)
	{
		if(i == 0 || i == node->end_pos - node->start_pos - 1)
			EXPECT_EQ(node->children[i]->type, SY_DOUBLE_QUOTE);
		else
			EXPECT_EQ(node->children[i]->type, SY_ALL);
		EXPECT_EQ(node->children[i]->token, tokens[i]);
	}
	ms_syntax_node_destroy(node);
	ms_lexical_analyze_destroy_token(tokens[0]);
	free(tokens);
	//empty string
	tokens = ms_lexical_analyze("\"\"");
	node = ms_parse_double_quoted_word(tokens, 0);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_DOUBLE_QUOTED_WORD);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 2);
	for(int i = 0; node->children[i]; i++)
	{
		if(i == 0 || i == node->end_pos - node->start_pos - 1)
			EXPECT_EQ(node->children[i]->type, SY_DOUBLE_QUOTE);
		else
			EXPECT_EQ(node->children[i]->type, SY_ALL);
		EXPECT_EQ(node->children[i]->token, tokens[i]);
	}
	ms_syntax_node_destroy(node);
	ms_lexical_analyze_destroy_token(tokens[0]);
	free(tokens);
}

TEST(Syntax_Analyze_Parse, SY_DOUBLE_QUOTED_WORD_FAIL)
{
	t_token **tokens = ms_lexical_analyze("\"Hello");
	t_syntax_node *node = ms_parse_double_quoted_word(tokens, 0);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_DOUBLE_QUOTED_WORD);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 3);
	EXPECT_EQ(node->children[0]->type, SY_DOUBLE_QUOTE);
	EXPECT_EQ(node->children[0]->token, tokens[0]);
	EXPECT_EQ(node->children[1]->type, SY_ALL);
	EXPECT_EQ(node->children[1]->token, tokens[1]);
	EXPECT_EQ(node->children[2]->type, SY_DECLINED);
	EXPECT_EQ(node->children[2]->token, tokens[1]);
	ms_syntax_node_destroy(node);
	ms_lexical_analyze_destroy_token(tokens[0]);
	free(tokens);
}