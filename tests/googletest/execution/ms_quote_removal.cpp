#include <gtest/gtest.h>
#include <string>

extern "C" {
    #include "execution.h"
	#include "libms.h"
	#include "lexical_analyze.h"
	#include "syntax_analyze.h"
	#include "semantic_analyze.h"
};

TEST(Execute_Expansion, ms_quote_removal)
{
	std::string input = "\"word\"";
	std::string expect_str = "word";
	t_token **token = ms_lexical_analyze(input.c_str());
	t_syntax_node *node;
	t_syntax_node *child_node;
	t_syntax_node **child_nodes;

	child_nodes = (t_syntax_node **)malloc(sizeof(t_syntax_node) * 4);
	child_nodes[0] = ms_syntax_node_create(SY_DOUBLE_QUOTE);
	child_nodes[0]->token = ms_dup_token(token[0]);
	child_nodes[0]->start_pos = 0;
	child_nodes[0]->end_pos = 1;
	child_nodes[1] = ms_syntax_node_create(SY_WORD);
	child_nodes[1]->token = ms_dup_token(token[1]);
	child_nodes[1]->start_pos = 1;
	child_nodes[1]->end_pos = 2;
	child_nodes[2] = ms_syntax_node_create(SY_DOUBLE_QUOTE);
	child_nodes[2]->token = ms_dup_token(token[2]);
	child_nodes[2]->start_pos = 2;
	child_nodes[2]->end_pos = 3;
	child_nodes[3] = NULL;

	child_node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	child_node->type = SY_DOUBLE_QUOTED_WORD;
	child_node->token = NULL;
	child_node->children = child_nodes;

	node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	node->type = SY_WORD_LIST;
	node->token = NULL;
	node->children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * 2);
	node->children[0] = child_node;
	node->children[1] = NULL;

	t_syntax_node *result = ms_quote_removal(node);

	ASSERT_NE(result, nullptr);
	ASSERT_NE(result->children[0], nullptr);
	ASSERT_STREQ(result->children[0]->token->token, expect_str.c_str());

	ms_syntax_node_destroy(result);
	ms_destroy_ntp2((void **)token,  ms_destroy_token_wrapper);
}