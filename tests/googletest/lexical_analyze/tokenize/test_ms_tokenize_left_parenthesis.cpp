#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Lexical_Tokenize, LeftParenthesis_Success)
{	
	const t_token expect_tokens[] = {
		{TK_LEFT_PARENTHESIS, "(", 0, 1},// "("
		{TK_LEFT_PARENTHESIS, "(", 1, 2}, // "("
		{TK_LEFT_PARENTHESIS, "(", 2, 3}, // "("
	};

	const Tokenize_TestCase test_cases[] = {
		{"(", 0, &expect_tokens[0], "LeftParenthesis SuccessCase 1"},
		{"((", 1, &expect_tokens[1], "LeftParenthesis SuccessCase 2"},
		{"(((", 2, &expect_tokens[2], "LeftParenthesis SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_left_parenthesis, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, LeftParenthesis_Failed)
{
	const t_token expect_tokens[] = {
		// diffrent string
		{TK_DECLINED, "", 0, 0}, // "test"
		// empty string
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "LeftParenthesis FailedCase 1"},
		{"", 0, &expect_tokens[1], "LeftParenthesis FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_left_parenthesis, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}