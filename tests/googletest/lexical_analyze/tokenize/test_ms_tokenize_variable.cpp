#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Lexical_Tokenize, Variable_Success){
	const t_token expect_tokens[] = {
		{TK_VARIABLE, "$?", 0, 2},// "$?"
		{TK_VARIABLE, "$PATH", 0, 5}, // "$PATH"
		{TK_VARIABLE, "$PS1", 0, 4}, // "$PS1"
		{TK_VARIABLE, "$_HOGEPATH", 0, 10}, // "$_HOGEPATH"
		{TK_VARIABLE, "$?", 5, 7}, // "echo $?"
	};

	const Tokenize_TestCase test_cases[] = {
		{"$?", 0, &expect_tokens[0], "Case 1 : $?"},
		{"$PATH", 0, &expect_tokens[1], "Case 2 : $PATH"},
		{"$PS1", 0, &expect_tokens[2], "Case 3 : $PS1"},
		{"$_HOGEPATH", 0, &expect_tokens[3], "Case 4 : $_HOGEPATH"},
		{"echo $?", 5, &expect_tokens[4], "Case 5 : echo $?"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_variable, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

TEST(Lexical_Tokenize, Variable_Failed){
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "test"
		{TK_DECLINED, "", 0, 0}, // "$"
		{TK_DECLINED, "", 0, 0}, // "$ "
		{TK_DECLINED, "", 0, 0}, // "$1"
		{TK_DECLINED, "", 0, 0} // ""
	};

	const Tokenize_TestCase test_cases[] = {
		{"test", 0, &expect_tokens[0], "Case 1 : test"},
		{"$", 0, &expect_tokens[1], "Case 2 : $"},
		{"$ ", 0, &expect_tokens[2], "Case 3 : $ "},
		{"$1", 0, &expect_tokens[3], "Case 4 : $1"},
		{"", 0, &expect_tokens[4], "Case 5 : empty string"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_variable, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));
}

