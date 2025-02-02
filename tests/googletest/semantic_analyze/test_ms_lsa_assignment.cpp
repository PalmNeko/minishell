#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

TEST(Semantic_Analyze, LSA_ASSIGNMENT_SUCCESS)
{
	t_lsa_assignment	*expect;
	t_lsa_assignment	*actual;
	t_syntax_node		*assignment_word_node;
	t_token				**tokens;
	const char			*str;

	str = "test=word";
	tokens = ms_lexical_analyze(str);
	assignment_word_node = ms_parse_assignment_word(tokens, 0);
	ASSERT_NE(assignment_word_node, nullptr);
	ASSERT_NE(assignment_word_node->children, nullptr);

	expect = (t_lsa_assignment *)malloc(sizeof(t_lsa_assignment));
	expect->name = ms_lsa_word_list(assignment_word_node->children[0]);
	expect->value = ms_lsa_word_list(assignment_word_node->children[2]);

	actual = ms_lsa_assignment(assignment_word_node);

	ASSERT_NE(actual, nullptr);	
	ASSERT_NE(actual->name, nullptr);
	ASSERT_NE(actual->value, nullptr);
	EXPECT_EQ(expect->name->word_list, actual->name->word_list);
	EXPECT_EQ(expect->value->word_list, actual->value->word_list);
	EXPECT_STREQ(expect->name->word_list->children[0]->token->token, actual->name->word_list->children[0]->token->token);
	EXPECT_STREQ(expect->value->word_list->children[0]->token->token, actual->value->word_list->children[0]->token->token);

	ms_lsa_assignment_destroy(expect);
	ms_lsa_assignment_destroy(actual);
	ms_syntax_node_destroy(assignment_word_node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

TEST(Semantic_Analyze, LSA_ASIGNMENT_SUCCESS_CASE2)
{
	t_lsa_assignment	*expect;
	t_lsa_assignment	*actual;
	t_syntax_node		*assignment_word_node;
	t_token				**tokens;
	const char			*str;

	str = "PATH=$PATH:/usr/bin";
	tokens = ms_lexical_analyze(str);
	assignment_word_node = ms_parse_assignment_word(tokens, 0);

	expect = (t_lsa_assignment *)malloc(sizeof(t_lsa_assignment));
	expect->name = ms_lsa_word_list(assignment_word_node->children[0]);
	expect->value = ms_lsa_word_list(assignment_word_node->children[2]);
	
	actual = ms_lsa_assignment(assignment_word_node);

	EXPECT_EQ(expect->name->word_list, actual->name->word_list);
	EXPECT_EQ(expect->value->word_list, actual->value->word_list);
	EXPECT_STREQ(expect->name->word_list->children[0]->token->token, actual->name->word_list->children[0]->token->token);
	EXPECT_STREQ(expect->value->word_list->children[0]->token->token, actual->value->word_list->children[0]->token->token);

	ms_lsa_assignment_destroy(expect);
	ms_lsa_assignment_destroy(actual);
	ms_syntax_node_destroy(assignment_word_node);
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}
