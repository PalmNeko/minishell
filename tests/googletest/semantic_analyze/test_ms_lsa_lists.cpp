#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
}

void ms_lsa_list_destroy_wrapper(void *list)
{
	ms_lsa_list_destroy((t_lsa_list *)list);
}

// single list
TEST(Semantic_Analyze, LSA_LISTS_SUCCESS_CASE1){
	t_lsa_list **expect;
	t_lsa_list **actual;
	t_syntax_node *lists_node;
	t_token **tokens;
	const char *str;

	str = "echo hello > outfile | cat outfile";
	tokens = ms_lexical_analyze(str);
	lists_node = ms_syntax_analyze(tokens);

	expect = (t_lsa_list **)malloc(sizeof(t_lsa_list *) * 2);
	expect[0] = ms_lsa_list(lists_node->children[0]);
	expect[1] = NULL;

	actual = ms_lsa_lists(lists_node->children[0]);

	ASSERT_NE(actual, nullptr);
	ASSERT_NE(actual[0], nullptr);
	EXPECT_EQ(expect[0]->type, actual[0]->type);
	ASSERT_NE(actual[0]->pipeline, nullptr);
	EXPECT_EQ(actual[0]->pipeline->commands[0]->args[0]->word_list, actual[0]->pipeline->commands[0]->args[0]->word_list);	

	ms_destroy_ntp2((void **)expect, ms_lsa_list_destroy_wrapper);
	ms_destroy_ntp2((void **)actual, ms_lsa_list_destroy_wrapper);
	ms_syntax_node_destroy(lists_node);
	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);
}

// list and list
TEST(Semantic_Analyze, LSA_LISTS_SUCCESS_CASE2){
	t_lsa_list **expect;
	t_lsa_list **actual;
	t_syntax_node *lists_node;
	t_token **tokens;
	const char *str;

	str = "echo hello > outfile | cat outfile && echo hello > outfile | cat outfile || echo hello > outfile | cat outfile";
	tokens = ms_lexical_analyze(str);
	lists_node = ms_syntax_analyze(tokens);

	expect = (t_lsa_list **)malloc(sizeof(t_lsa_list *) * 4);
	expect[0] = ms_lsa_list(lists_node->children[0]->children[0]);
	expect[1] = ms_lsa_list(lists_node->children[0]->children[2]);
	expect[1]->type = LSA_LIST_AND;
	expect[2] = ms_lsa_list(lists_node->children[0]->children[4]);
	expect[2]->type = LSA_LIST_OR;
	expect[3] = NULL;

	actual = ms_lsa_lists(lists_node->children[0]);

	ASSERT_NE(actual, nullptr);
	ASSERT_NE(actual[0], nullptr);
	EXPECT_EQ(expect[0]->type, actual[0]->type);
	ASSERT_NE(actual[0]->pipeline, nullptr);
	EXPECT_EQ(actual[0]->pipeline->commands[0]->args[0]->word_list, actual[0]->pipeline->commands[0]->args[0]->word_list);	
	ASSERT_NE(actual[1], nullptr);
	EXPECT_EQ(expect[1]->type, actual[1]->type);
	ASSERT_NE(actual[1]->pipeline, nullptr);
	EXPECT_EQ(actual[1]->pipeline->commands[0]->args[0]->word_list, actual[1]->pipeline->commands[0]->args[0]->word_list);	
	ASSERT_NE(actual[2], nullptr);
	EXPECT_EQ(expect[2]->type, actual[2]->type);
	ASSERT_NE(actual[2]->pipeline, nullptr);
	EXPECT_EQ(actual[2]->pipeline->commands[0]->args[0]->word_list, actual[2]->pipeline->commands[0]->args[0]->word_list);

	ms_destroy_ntp2((void **)expect, ms_lsa_list_destroy_wrapper);
	ms_destroy_ntp2((void **)actual, ms_lsa_list_destroy_wrapper);
	ms_syntax_node_destroy(lists_node);
	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);
}