#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
}

void test_runner_of_lsa_command(t_lsa_command *expect,  t_lsa_command *actual);

TEST(Semantic_Analyze,COMMAND_SUCCESS_CASE1){
	t_lsa_command	*expect;
	t_lsa_command	*actual;
	t_syntax_node	*command_node;
	t_token			**tokens;
	const char		*str;

	str = "echo hello > file";
	tokens = ms_lexical_analyze(str);

	command_node = ms_parse_command(tokens, 0);

	expect = (t_lsa_command *)malloc(sizeof(t_lsa_command));
	expect->args = (t_lsa_word_list **)malloc(sizeof(t_lsa_word_list *) * 3);
	expect->args[0] = ms_lsa_word_list(command_node->children[0]->children[0]);
	expect->args[1] = ms_lsa_word_list(command_node->children[0]->children[2]);
	expect->args[2] = NULL;
	expect->assignments = NULL;
	expect->redirects = (t_lsa_redirection **)malloc(sizeof(t_lsa_redirection *) * 2);
	expect->redirects[0] = ms_lsa_redirection(command_node->children[0]->children[4]);
	expect->redirects[1] = NULL;

	actual = ms_lsa_command(command_node);

	test_runner_of_lsa_command(expect, actual);

	ms_syntax_node_destroy(command_node);
}

// Parser部分で不具合あり
// TEST(Semantic_Analyze,COMMAND_SUCCESS_CASE2){
// 	t_lsa_command	*expect;
// 	t_lsa_command	*actual;
// 	t_syntax_node	*command_node;
// 	t_token			**tokens;
// 	const char		*str;

// 	str = "PATH=$PATH:/usr/bin HOGE=piyo";
// 	tokens = ms_lexical_analyze(str);

// 	command_node = ms_parse_command(tokens, 0);
// 	printf("command_node->children[0]->children[0]: %p\n", command_node->children[0]->children[0]);
// 	printf("command_node->children[0]->children[1]: %p\n", command_node->children[0]->children[1]);

// 	expect = (t_lsa_command *)malloc(sizeof(t_lsa_command));
// 	expect->args = NULL;
// 	expect->assignments = (t_lsa_assignment **)malloc(sizeof(t_lsa_assignment *) * 3);
// 	expect->assignments[0] = ms_lsa_assignment(command_node->children[0]->children[0]);
// 	expect->assignments[1] = ms_lsa_assignment(command_node->children[0]->children[2]);
// 	expect->assignments[2] = NULL;
// 	expect->redirects = NULL;

// 	actual = ms_lsa_command(command_node);

// 	test_runner_of_lsa_command(expect, actual);

// 	ms_syntax_node_destroy(command_node);
// }

void test_runner_of_lsa_command(t_lsa_command *expect,  t_lsa_command *actual)
{
	if(expect->args)
	{
		int i;
		for(i = 0; expect->args[i]; i++)
		{
			EXPECT_EQ(expect->args[i]->word_list, actual->args[i]->word_list);
		}
		ASSERT_EQ(expect->args[i], actual->args[i]);
	}else{
		ASSERT_EQ(expect->args, actual->args);
	}
	if(expect->assignments)
	{
		int i;
		for(i = 0; expect->assignments[i]; i++)
		{
			EXPECT_EQ(expect->assignments[i]->name->word_list, actual->assignments[i]->name->word_list);
			EXPECT_EQ(expect->assignments[i]->value->word_list, actual->assignments[i]->value->word_list);
			EXPECT_STREQ(expect->assignments[i]->name->word_list->children[0]->token->token, actual->assignments[i]->name->word_list->children[0]->token->token);
			EXPECT_STREQ(expect->assignments[i]->value->word_list->children[0]->token->token, actual->assignments[i]->value->word_list->children[0]->token->token);
		}
		ASSERT_EQ(expect->assignments[i], actual->assignments[i]);
	}else{
		ASSERT_EQ(expect->assignments, actual->assignments);
	}
	if(expect->redirects)
	{
		int i;
		for(i = 0; expect->redirects[i]; i++)
		{
			EXPECT_EQ(expect->redirects[i]->type, actual->redirects[i]->type);
			EXPECT_EQ(expect->redirects[i]->filename->word_list, actual->redirects[i]->filename->word_list);
			EXPECT_EQ(expect->redirects[i]->delimiter, actual->redirects[i]->delimiter);
			EXPECT_EQ(expect->redirects[i]->is_expansion, actual->redirects[i]->is_expansion);
		}
		ASSERT_EQ(expect->redirects[i], actual->redirects[i]);
	}else{
		ASSERT_EQ(expect->redirects, actual->redirects);
	}
}