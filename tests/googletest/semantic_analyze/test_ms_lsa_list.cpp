#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

// single list
TEST(Semantic_Analyze, LSA_LIST_SUCCESS_CASE1){
	t_lsa_list *expect;
	t_lsa_list *actual;
	t_syntax_node *list_node;
	t_token **tokens;
	const char *str;

	str = "echo hello > outfile | cat outfile";
	tokens = ms_lexical_analyze(str);
	list_node = ms_parse_list(tokens, 0);

	expect = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->type = LSA_LIST_ALWAYS;
	expect->pipeline = ms_lsa_pipeline(list_node->children[0]);
	expect->compound_list = NULL;

	actual = ms_lsa_list(list_node->children[0]);

	ASSERT_NE(actual, nullptr);
	EXPECT_EQ(expect->type, actual->type);
	EXPECT_EQ(actual->compound_list, nullptr);
	ASSERT_NE(actual->pipeline, nullptr);
	ASSERT_NE(actual->pipeline->commands, nullptr);
	EXPECT_EQ(expect->pipeline->commands[0]->args[0]->word_list, actual->pipeline->commands[0]->args[0]->word_list);
	EXPECT_EQ(expect->pipeline->commands[0]->args[1]->word_list, actual->pipeline->commands[0]->args[1]->word_list);

	ms_lsa_list_destroy(expect);
	ms_lsa_list_destroy(actual);
	ms_syntax_node_destroy(list_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

// compound list
TEST(Semantic_Analyze, LSA_LIST_SUCCESS_CASE2){
	t_lsa_list *expect;
	t_lsa_list *actual;
	t_syntax_node *list_node;
	t_token **tokens;
	const char *str;

	str = "(echo hello > outfile)";
	tokens = ms_lexical_analyze(str);
	list_node = ms_parse_compound_list(tokens, 0);

	expect = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->type = LSA_LIST_ALWAYS;
	expect->pipeline = NULL;
	expect->compound_list = (t_lsa_list **)malloc(sizeof(t_lsa_list *) * 2);
	expect->compound_list[0] = ms_lsa_list(list_node->children[1]->children[0]);
	expect->compound_list[1] = NULL;

	actual = ms_lsa_list(list_node);

	ASSERT_NE(actual, nullptr);
	EXPECT_EQ(expect->type, actual->type);
	EXPECT_EQ(actual->pipeline, nullptr);
	ASSERT_NE(actual->compound_list, nullptr);
	EXPECT_EQ(expect->compound_list[0]->type, actual->compound_list[0]->type);
	ASSERT_NE(actual->compound_list[0]->pipeline, nullptr);
	ASSERT_NE(actual->compound_list[0]->pipeline->commands, nullptr);
	ASSERT_NE(actual->compound_list[0]->pipeline->commands[0]->args, nullptr);
	ASSERT_NE(actual->compound_list[0]->pipeline->commands[0]->args[0]->word_list, nullptr);
	ASSERT_NE(expect->compound_list[0]->pipeline, nullptr);

	ms_lsa_list_destroy(expect);
	ms_lsa_list_destroy(actual);
	ms_syntax_node_destroy(list_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}