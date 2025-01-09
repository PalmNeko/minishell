#include <gtest/gtest.h>
#include <iostream>


extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "ms_test.h"
};


void test_runnner_of_ms_parse_terminal(t_syntax_node *node, t_syntax_type type, t_token **tokens, int pos);

// SY_DECLINED
TEST(Syntax_Analyze_Parse_Terminal, SY_DECLINED_SUCESS)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_declined(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_IDENTIFY
TEST(Syntax_Analyze_Parse_Terminal, SY_IDENTIFY_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("test");
	t_syntax_node *node = ms_parse_identify(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_IDENTIFY, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_IDENTIFY_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_identify(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_WORD
TEST(Syntax_Analyze_Parse_Terminal, SY_WORD_SUCESS)
{
	t_token **tokens = ms_lexical_analyze("tehst%");
	t_syntax_node *node = ms_parse_word(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_WORD, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_WORD_FAIL)
{
	t_token **tokens = ms_lexical_analyze("|");
	t_syntax_node *node = ms_parse_word(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_BLANK
TEST(Syntax_Analyze_Parse_Terminal, SY_BLANK_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze(" ");
	t_syntax_node *node = ms_parse_blank(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_BLANK, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_BLANK_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_blank(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_NEWLINE
TEST(Syntax_Analyze_Parse_Terminal, SY_NEWLINE_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("\n");
	t_syntax_node *node = ms_parse_newline(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_NEWLINE, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_NEWLINE_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_newline(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_VARIABLE
TEST(Syntax_Analyze_Parse_Terminal, SY_VARIABLE_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("$test");
	t_syntax_node *node = ms_parse_variable(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_VARIABLE, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_VARIABLE_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_variable(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_LIST_TOKEN
TEST(Syntax_Analyze_Parse_Terminal, SY_LIST_TOKEN_SUCCESS)
{
	// ||
	t_token **tokens = ms_lexical_analyze("||");
	t_syntax_node *node = ms_parse_list_token(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_LIST_TOKEN, tokens, 0);
	// &&
	tokens = ms_lexical_analyze("&&");
	node = ms_parse_list_token(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_LIST_TOKEN, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_LIST_TOKEN_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_list_token(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_PIPE
TEST(Syntax_Analyze_Parse_Terminal, SY_PIPE_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("|");
	t_syntax_node *node = ms_parse_pipe(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_PIPE, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_PIPE_FAIL)
{
	t_token **tokens = ms_lexical_analyze("1");
	t_syntax_node *node = ms_parse_pipe(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_EQUALS
TEST(Syntax_Analyze_Parse_Terminal, SY_EQUAL_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("=");
	t_syntax_node *node = ms_parse_equal(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_EQUALS, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_EQUAL_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_equal(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_SINGLE_QUOTE
TEST(Syntax_Analyze_Parse_Terminal, SY_SINGLE_QUOTE_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("'");
	t_syntax_node *node = ms_parse_single_quote(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_SINGLE_QUOTE, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_SINGLE_QUOTE_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_single_quote(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_DOUBLE_QUOTE
TEST(Syntax_Analyze_Parse_Terminal, SY_DOUBLE_QUOTE_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("\"");
	t_syntax_node *node = ms_parse_double_quote(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DOUBLE_QUOTE, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_DOUBLE_QUOTE_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_double_quote(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_REDIRECTION
TEST(Syntax_Analyze_Parse_Terminal, SY_REDIRECTION_SUCCESS)
{
	// >
	t_token **tokens = ms_lexical_analyze(">");
	t_syntax_node *node = ms_parse_redirection(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_REDIRECTION, tokens, 0);
	// >>
	tokens = ms_lexical_analyze(">>");
	node = ms_parse_redirection(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_REDIRECTION, tokens, 0);
	// <
	tokens = ms_lexical_analyze("<");
	node = ms_parse_redirection(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_REDIRECTION, tokens, 0);
	// <<
	tokens = ms_lexical_analyze("<<");
	node = ms_parse_redirection(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_REDIRECTION, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_REDIRECTION_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_redirection(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_LEFT_PARENTHESIS
TEST(Syntax_Analyze_Parse_Terminal, SY_LEFT_PARENTHESIS_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("(");
	t_syntax_node *node = ms_parse_left_parenthesis(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_LEFT_PARENTHESIS, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_LEFT_PARENTHESIS_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_left_parenthesis(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_RIGHT_PARENTHESIS
TEST(Syntax_Analyze_Parse_Terminal, SY_RIGHT_PARENTHESIS_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze(")");
	t_syntax_node *node = ms_parse_right_parenthesis(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_RIGHT_PARENTHESIS, tokens, 0);
}

TEST(Syntax_Analyze_Parse_Terminal, SY_RIGHT_PARENTHESIS_FAIL)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_right_parenthesis(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_DECLINED, tokens, 0);
}

// SY_ALL
TEST(Syntax_Analyze_Parse_Terminal, SY_ALL_SUCCESS)
{
	t_token **tokens = ms_lexical_analyze("a");
	t_syntax_node *node = ms_parse_all(tokens, 0);
	test_runnner_of_ms_parse_terminal(node, SY_ALL, tokens, 0);
}

void test_runnner_of_ms_parse_terminal(t_syntax_node *node, t_syntax_type type, t_token **tokens, int pos)
{
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, type);
	EXPECT_EQ(node->token, tokens[pos]);
	EXPECT_EQ(node->start_pos, pos);
	EXPECT_EQ(node->end_pos, pos + 1);
	ms_syntax_node_destroy(node);
	ms_lexical_analyze_destroy_token(tokens[pos]);
	free(tokens);
}
