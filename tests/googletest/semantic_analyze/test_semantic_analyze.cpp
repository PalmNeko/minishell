#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
}

// single list
TEST(Semantic_Analyze, SEMANTIC_ANALYZE_SUCCESS_CASE1)
{
	t_lsa *expect;
	t_lsa *actual;
	t_syntax_node *node;
	t_token **tokens;
	const char *str;

	str = "echo hello > outfile | cat outfile";

	tokens = ms_lexical_analyze(str);
	node = ms_syntax_analyze(tokens);

	expect = (t_lsa *)malloc(sizeof(t_lsa));
	expect->lists = (t_lsa_list **)malloc(sizeof(t_lsa_list *) * 2);
	expect->lists[0] = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->lists[0]->type = LSA_LIST_ALWAYS;
	expect->lists[0]->pipeline = ms_lsa_pipeline(node->children[0]->children[0]);
	expect->lists[0]->compound_list = NULL;
	expect->lists[1] = NULL;

	actual = semantic_analyze(node);

	ASSERT_NE(actual, nullptr);
	ASSERT_NE(actual->lists, nullptr);
	ASSERT_NE(actual->lists[0], nullptr);
	EXPECT_EQ(expect->lists[0]->type, actual->lists[0]->type);
	ASSERT_NE(actual->lists[0]->pipeline, nullptr);
	ASSERT_NE(actual->lists[0]->pipeline->commands, nullptr);
	EXPECT_EQ(expect->lists[0]->pipeline->commands[0]->args[0]->word_list->children[0]->token, actual->lists[0]->pipeline->commands[0]->args[0]->word_list->children[0]->token);
	EXPECT_EQ(expect->lists[0]->pipeline->commands[0]->args[1]->word_list->children[0]->token, actual->lists[0]->pipeline->commands[0]->args[1]->word_list->children[0]->token);

	ms_lsa_destroy(expect);
	ms_lsa_destroy(actual);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);
}

// lists test
TEST(Semantic_Analyze, SEMANTIC_ANALYZE_SUCCESS_CASE2)
{
	t_lsa *expect;
	t_lsa *actual;
	t_syntax_node *node;
	t_token **tokens;
	const char *str;

	str = "echo hello > outfile | cat outfile && echo hello > outfile | cat outfile || echo hello > outfile | cat outfile";

	tokens = ms_lexical_analyze(str);
	node = ms_syntax_analyze(tokens);

	expect = (t_lsa *)malloc(sizeof(t_lsa));
	expect->lists = (t_lsa_list **)malloc(sizeof(t_lsa_list *) * 4);
	expect->lists[0] = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->lists[0]->type = LSA_LIST_ALWAYS;
	expect->lists[0]->pipeline = ms_lsa_pipeline(node->children[0]->children[0]);
	expect->lists[0]->compound_list = NULL;
	expect->lists[1] = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->lists[1]->type = LSA_LIST_AND;
	expect->lists[1]->pipeline = ms_lsa_pipeline(node->children[0]->children[2]);
	expect->lists[1]->compound_list = NULL;
	expect->lists[2] = (t_lsa_list *)malloc(sizeof(t_lsa_list));
	expect->lists[2]->type = LSA_LIST_OR;
	expect->lists[2]->pipeline = ms_lsa_pipeline(node->children[0]->children[4]);
	expect->lists[2]->compound_list = NULL;
	expect->lists[3] = NULL;

	actual = semantic_analyze(node);

	ASSERT_NE(actual, nullptr);
	ASSERT_NE(actual->lists, nullptr);
	ASSERT_NE(actual->lists[0], nullptr);
	EXPECT_EQ(expect->lists[0]->type, actual->lists[0]->type);
	ASSERT_NE(actual->lists[0]->pipeline, nullptr);
	ASSERT_NE(actual->lists[0]->pipeline->commands, nullptr);
	EXPECT_EQ(expect->lists[0]->pipeline->commands[0]->args[0]->word_list->children[0]->token, actual->lists[0]->pipeline->commands[0]->args[0]->word_list->children[0]->token);
	EXPECT_EQ(expect->lists[0]->pipeline->commands[0]->args[1]->word_list->children[0]->token, actual->lists[0]->pipeline->commands[0]->args[1]->word_list->children[0]->token);
	ASSERT_NE(actual->lists[1], nullptr);
	EXPECT_EQ(expect->lists[1]->type, actual->lists[1]->type);
	ASSERT_NE(actual->lists[1]->pipeline, nullptr);
	ASSERT_NE(actual->lists[1]->pipeline->commands, nullptr);
	EXPECT_EQ(expect->lists[1]->pipeline->commands[0]->args[0]->word_list->children[0]->token, actual->lists[1]->pipeline->commands[0]->args[0]->word_list->children[0]->token);
	EXPECT_EQ(expect->lists[1]->pipeline->commands[0]->args[1]->word_list->children[0]->token, actual->lists[1]->pipeline->commands[0]->args[1]->word_list->children[0]->token);
	ASSERT_NE(actual->lists[2], nullptr);
	EXPECT_EQ(expect->lists[2]->type, actual->lists[2]->type);
	ASSERT_NE(actual->lists[2]->pipeline, nullptr);
	ASSERT_NE(actual->lists[2]->pipeline->commands, nullptr);
	EXPECT_EQ(expect->lists[2]->pipeline->commands[0]->args[0]->word_list->children[0]->token, actual->lists[2]->pipeline->commands[0]->args[0]->word_list->children[0]->token);

	ms_lsa_destroy(expect);
	ms_lsa_destroy(actual);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);
}

// heredoc test