#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
}

void test_runner_of_ms_lsa_redirection(t_lsa_redirection *expect,  t_lsa_redirection *actual);

TEST(Semantic_Analyze, REDIRECTION_SUCCESS)
{
	t_lsa_redirection	*expect;
	t_lsa_redirection	*actual;
	t_syntax_node		*redirection_node;
	t_token				**tokens;
	const char			*str;

	
	str = ">> word";
	tokens = ms_lexical_analyze(str);
	redirection_node = ms_parse_redirection_word(tokens, 0);

	expect = (t_lsa_redirection *)malloc(sizeof(t_lsa_redirection));
	expect->type = LSA_RD_APPEND;
	expect->filename = ms_lsa_word_list(redirection_node->children[2]);
	expect->delimiter = NULL;
	expect->heredoc_input = NULL;
	expect->is_expansion = false;

	actual = ms_lsa_redirection(redirection_node);

	test_runner_of_ms_lsa_redirection(expect, actual);

	ms_syntax_node_destroy(redirection_node);
}

void test_runner_of_ms_lsa_redirection(t_lsa_redirection *expect,  t_lsa_redirection *actual)
{
	const char *expect_str = expect->filename->word_list->children[0]->token->token;
	const char *actual_str = actual->filename->word_list->children[0]->token->token;

	EXPECT_EQ(expect->type, actual->type);
	EXPECT_STREQ(expect_str, actual_str);
	EXPECT_EQ(expect->delimiter, actual->delimiter);
	EXPECT_EQ(expect->heredoc_input, actual->heredoc_input);
	EXPECT_EQ(expect->is_expansion, actual->is_expansion);
}
