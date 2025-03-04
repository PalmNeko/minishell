#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexical_analyze.h"
};

TEST(Lexical_Tokenize, Redirection_Success)
{	
	const t_token expect_tokens[] = {
		{TK_REDIRECTION, "<<", 0, 2},// "<<"
		{TK_REDIRECTION, "<", 0, 1}, // "<"
		{TK_REDIRECTION, ">>", 0, 2}, // ">>"
		{TK_REDIRECTION, ">", 0, 1}, // ">"
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"<<", 0, &expect_tokens[0], "Redirection SuccessCase 1"},
		{"<", 0, &expect_tokens[1], "Redirection SuccessCase 2"},
		{">>", 0, &expect_tokens[2], "Redirection SuccessCase 3"},
		{">", 0, &expect_tokens[3], "Redirection SuccessCase 4"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_redirection, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}

TEST(Lexical_Tokenize, Redirection_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "Redirection FailedCase 1"},
		{"", 0, &expect_tokens[1], "Redirection FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_redirection, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}