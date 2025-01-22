#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

TEST(Semantic_Analyze, LSA_PIPELINE_SUCCESS)
{
	t_lsa_pipeline	*expect;
	t_lsa_pipeline	*actual;
	t_syntax_node	*pipeline_node;
	t_token			**tokens;
	const char		*str;

	str = "echo hello > file";
	tokens = ms_lexical_analyze(str);
	pipeline_node = ms_parse_pipeline(tokens, 0);

	expect = (t_lsa_pipeline *)malloc(sizeof(t_lsa_pipeline));
	expect->commands = (t_lsa_command **)malloc(sizeof(t_lsa_command *) * 2);
	expect->commands[0] = ms_lsa_command(pipeline_node->children[0]);
	expect->commands[1] = NULL;

	actual = ms_lsa_pipeline(pipeline_node);

	EXPECT_EQ(expect->commands[0]->args[0]->word_list->children[0]->token->token, actual->commands[0]->args[0]->word_list->children[0]->token->token);
	EXPECT_EQ(expect->commands[0]->args[1]->word_list->children[0]->token->token, actual->commands[0]->args[1]->word_list->children[0]->token->token);
	EXPECT_EQ(expect->commands[0]->redirects[0]->filename->word_list->children[0]->token->token, actual->commands[0]->redirects[0]->filename->word_list->children[0]->token->token);

	ms_lsa_pipeline_destroy(expect);
	ms_lsa_pipeline_destroy(actual);
	ms_syntax_node_destroy(pipeline_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

TEST(Semantic_Analyze, LSA_PIPELINE_SUCCESS_CASE2)
{
	t_lsa_pipeline	*expect;
	t_lsa_pipeline	*actual;
	t_syntax_node	*pipeline_node;
	t_token			**tokens;
	const char		*str;

	str = "echo hello > outfile | cat outfile";
	tokens = ms_lexical_analyze(str);
	pipeline_node = ms_parse_pipeline(tokens, 0);

	expect = (t_lsa_pipeline *)malloc(sizeof(t_lsa_pipeline));
	expect->commands = (t_lsa_command **)malloc(sizeof(t_lsa_command *) * 3);
	expect->commands[0] = ms_lsa_command(pipeline_node->children[0]);
	expect->commands[1] = ms_lsa_command(pipeline_node->children[4]);
	expect->commands[2] = NULL;

	actual = ms_lsa_pipeline(pipeline_node);

	EXPECT_EQ(expect->commands[0]->args[0]->word_list->children[0]->token->token, actual->commands[0]->args[0]->word_list->children[0]->token->token);
	EXPECT_EQ(expect->commands[0]->args[1]->word_list->children[0]->token->token, actual->commands[0]->args[1]->word_list->children[0]->token->token);
	EXPECT_EQ(expect->commands[0]->redirects[0]->filename->word_list->children[0]->token->token, actual->commands[0]->redirects[0]->filename->word_list->children[0]->token->token);
	EXPECT_EQ(expect->commands[1]->args[0]->word_list->children[0]->token->token, actual->commands[1]->args[0]->word_list->children[0]->token->token);

	ms_lsa_pipeline_destroy(expect);
	ms_lsa_pipeline_destroy(actual);
	ms_syntax_node_destroy(pipeline_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}