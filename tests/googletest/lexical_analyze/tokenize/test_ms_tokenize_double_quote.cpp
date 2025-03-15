#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexical_analyze.h"
};

TEST(Lexical_Tokenize, DoubleQuote_Success)
{	
	const t_token expect_tokens[] = {
		{TK_DOUBLE_QUOTE, "\"", 0, 1},// "\""
		{TK_DOUBLE_QUOTE, "\"", 1, 2}, // "\""
		{TK_DOUBLE_QUOTE, "\"", 2, 3}, // "\""
	};

	const Tokenize_TestCase test_cases[] = {
		{"\"", 0, &expect_tokens[0], "DoubleQuote SuccessCase 1"},
		{"\"\"", 1, &expect_tokens[1], "DoubleQuote SuccessCase 2"},
		{"\"\"\"", 2, &expect_tokens[2], "DoubleQuote SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_double_quote, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, DoubleQuote_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "DoubleQuote FailedCase 1"},
		{"", 0, &expect_tokens[1], "DoubleQuote FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_double_quote, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}
