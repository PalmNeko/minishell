#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexical_analyze.h"
};

TEST(Lexical_Tokenize, SingleQuote_Success)
{	
	const t_token expect_tokens[] = {
		{TK_SINGLE_QUOTE, "'", 0, 1},// "'"
		{TK_SINGLE_QUOTE, "'", 1, 2}, // "'"
		{TK_SINGLE_QUOTE, "'", 2, 3}, // "'"
	};

	const Tokenize_TestCase test_cases[] = {
		{"'", 0, &expect_tokens[0], "SingleQuote SuccessCase 1"},
		{"''", 1, &expect_tokens[1], "SingleQuote SuccessCase 2"},
		{"'''", 2, &expect_tokens[2], "SingleQuote SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_single_quote, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, SingleQuote_Failed)
{
	const t_token expect_tokens[] = {
		// diffrent string
		{TK_DECLINED, "", 0, 0}, // "test"
		// empty string
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "SingleQuote FailedCase 1"},
		{"", 0, &expect_tokens[1], "SingleQuote FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_single_quote, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}