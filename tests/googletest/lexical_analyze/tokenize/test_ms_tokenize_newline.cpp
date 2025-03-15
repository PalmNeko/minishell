#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexical_analyze.h"
};

TEST(Lexical_Tokenize, Newline_Success)
{	
	const t_token expect_tokens[] = {
		{TK_NEWLINE, "\n", 0, 1},// "\n"
		{TK_NEWLINE, "\n", 1, 2}, // "\n"
		{TK_NEWLINE, "\n", 2, 3}, // "\n"
	};

	const Tokenize_TestCase test_cases[] = {
		{"\n", 0, &expect_tokens[0], "Newline SuccessCase 1"},
		{"\n\n", 1, &expect_tokens[1], "Newline SuccessCase 2"},
		{"\n\n\n", 2, &expect_tokens[2], "Newline SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_newline, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, Newline_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "Newline FailedCase 1"},
		{"", 0, &expect_tokens[1], "Newline FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_newline, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}