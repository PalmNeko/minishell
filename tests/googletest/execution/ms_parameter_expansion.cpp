#include <gtest/gtest.h>
#include <string>

extern "C" {
    #include "execution.h"
	#include "libms.h"
	#include "lexer.h"
	#include "syntax_analyze.h"
	#include "semantic_analyze.h"
};

TEST(Execute_Expansion, ms_parameter_expansion)
{
	std::string input = "$HOME";
	char *expect_str = getenv("HOME");
	t_token **token = ms_lexical_analyze(input.c_str());
	t_syntax_node *node;
	t_syntax_node *child_node;

	child_node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	child_node->type = SY_VARIABLE;
	child_node->token = ms_dup_token(token[0]);
	child_node->children = NULL;

	node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	node->type = SY_WORD;
	node->token = NULL;
	node->children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * 2);
	node->children[0] = child_node;
	node->children[1] = NULL;

	t_syntax_node *result = ms_parameter_expansion(node);
	ASSERT_STREQ(result->children[0]->token->token, expect_str);

	ms_syntax_node_destroy(result);
	ms_destroy_ntp2((void **)token, ms_lexical_analyze_destroy_token_wrapper);
}

TEST(Execute_Expansion, ms_parameter_expansion2)
{
	std::string input = "\"\"";
	std::string expect_str1 = "\"";
	std::string expect_str2 = "\"";
	t_token **token = ms_lexical_analyze(input.c_str());
	t_syntax_node *node;
	t_syntax_node *child_node;
	t_syntax_node **child_nodes;

	child_nodes = (t_syntax_node **)malloc(sizeof(t_syntax_node) * 3);
	child_nodes[0] = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	child_nodes[0]->type = SY_DOUBLE_QUOTE;
	child_nodes[0]->token = ms_dup_token(token[0]);
	child_nodes[0]->children = NULL;
	child_nodes[1] = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	child_nodes[1]->type = SY_DOUBLE_QUOTE;
	child_nodes[1]->token = ms_dup_token(token[1]);
	child_nodes[1]->children = NULL;
	child_nodes[2] = NULL;

	child_node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	child_node->type = SY_DOUBLE_QUOTED_WORD;
	child_node->token = NULL;
	child_node->children = child_nodes;

	node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	node->type = SY_WORD;
	node->token = NULL;
	node->children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * 2);
	node->children[0] = child_node;
	node->children[1] = NULL;

	t_syntax_node *result = ms_parameter_expansion(node);
	ASSERT_NE(result, nullptr);
	ASSERT_NE(result->children[0], nullptr);
	ASSERT_NE(result->children[0]->children[0], nullptr);
	ASSERT_STREQ(result->children[0]->children[0]->token->token, expect_str1.c_str());
	ASSERT_NE(result->children[0]->children[1], nullptr);
	ASSERT_STREQ(result->children[0]->children[1]->token->token, expect_str2.c_str());

	ms_syntax_node_destroy(result);
	ms_destroy_ntp2((void **)token, ms_lexical_analyze_destroy_token_wrapper);
}