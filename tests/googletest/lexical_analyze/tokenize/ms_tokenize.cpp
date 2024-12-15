#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Identify_TEST, Success_Case)
{	
	const t_token expect_tokens[] = {
		{TK_IDENTIFY, "_test", 0, 5},// "_test"
		{TK_IDENTIFY, "test", 1, 5}, // "&test"
		{TK_IDENTIFY, "es", 1, 3}, // "3es3#t"
	};

	const Tokenize_TestCase test_cases[] = {
		{"_test", 0, &expect_tokens[0], "Identify SuccessCase 1"},
		{"&test", 1, &expect_tokens[1], "Identify SuccessCase 2"},
		{"3es3#t", 1, &expect_tokens[2], "Identify SuccessCase 3"},	
	};

	// execute the test
	ms_tokenize_test_runner(
		ms_tokenize_identify, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Identify_TEST, Failed_Case)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "5test"
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"5test", 0, &expect_tokens[0], "Identify FailedCase 1"},
		{"", 0, &expect_tokens[1], "Identify FailedCase 2"},
	};

	// execute the test
	ms_tokenize_test_runner(
		ms_tokenize_identify, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}