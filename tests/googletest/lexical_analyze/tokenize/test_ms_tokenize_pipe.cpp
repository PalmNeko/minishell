#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexical_analyze.h"
};

TEST(Lexical_Tokenize, Pipe_Success)
{	
	const t_token expect_tokens[] = {
		{TK_PIPE, "|", 0, 1},// "|"
		{TK_PIPE, "|", 2, 3}, // "| |"
		{TK_PIPE, "|", 4, 5}, // "| | |"
	};

	const Tokenize_TestCase test_cases[] = {
		{"|", 0, &expect_tokens[0], "Pipe SuccessCase 1"},
		{"| |", 2, &expect_tokens[1], "Pipe SuccessCase 2"},
		{"| | |", 4, &expect_tokens[2], "Pipe SuccessCase 3"},	
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_pipe, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}

TEST(Lexical_Tokenize, Pipe_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "Pipe FailedCase 1"},
		{"", 0, &expect_tokens[1], "Pipe FailedCase 2"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_pipe, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}