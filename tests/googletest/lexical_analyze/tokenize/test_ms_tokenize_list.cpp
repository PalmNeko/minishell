#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Lexical_Tokenize, List_Success)
{	
	const t_token expect_tokens[] = {
		{TK_LIST, "&&", 0, 2},// "&&"
		{TK_LIST, "||", 0, 2}, // "||"
		{TK_LIST, "&&", 2, 4}, // "&&&&"
		{TK_LIST, "||", 2, 4}, // "||||"
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"&&", 0, &expect_tokens[0], "List SuccessCase 1"},
		{"||", 0, &expect_tokens[1], "List SuccessCase 2"},
		{"&&&&", 2, &expect_tokens[2], "List SuccessCase 3"},
		{"||||", 2, &expect_tokens[3], "List SuccessCase 4"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_list, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}

TEST(Lexical_Tokenize, List_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // "|"
		{TK_DECLINED, "", 0, 0}, // "|&
		{TK_DECLINED, "", 0, 0}, // "| |"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"te", 0, &expect_tokens[0], "List FailedCase 1"},
		{"|", 0, &expect_tokens[1], "List FailedCase 2"},
		{"|&", 0, &expect_tokens[2], "List FailedCase 3"},
		{"| |", 0, &expect_tokens[3], "List FailedCase 4"},
		{"", 0, &expect_tokens[4], "List FailedCase 5"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_list, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}
