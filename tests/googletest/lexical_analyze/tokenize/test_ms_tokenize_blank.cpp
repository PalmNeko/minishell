#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Lexical_Tokenize, Blank_Success)
{	
	const t_token expect_tokens[] = {
		{TK_BLANK, "   ", 0, 3},// " "
		{TK_BLANK, "\t\t", 0, 2}, // " "
		{TK_BLANK, " \t \t", 0, 4}, // " "
	};

	const Tokenize_TestCase test_cases[] = {
		{"   ", 0, &expect_tokens[0], "Blank SuccessCase 1"},
		{"\t\t", 0, &expect_tokens[1], "Blank SuccessCase 2"},
		{" \t \t", 0, &expect_tokens[2], "Blank SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_blank, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, Blank_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "Blank FailedCase 1"},
		{"", 0, &expect_tokens[1], "Blank FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_blank, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}