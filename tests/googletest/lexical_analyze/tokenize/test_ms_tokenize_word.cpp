#include <gtest/gtest.h>
#include <iostream>
#include "./ms_tokenize_test_types.h"

extern "C"
{
	#include "lexer.h"
};

TEST(Lexical_Tokenize, Word_Success)
{	
	const t_token expect_tokens[] = {
		{TK_WORD, "hello", 0, 5},// "hello"
		{TK_WORD, "%^" , 0, 2}, // "%^"
		{TK_WORD, "$" , 0, 1}, // "$"
		{TK_WORD, "&hhi" , 0, 4}, // "&hhi"
		{TK_WORD, "hello", 0, 5}, // "hello world"
		{TK_WORD, "world", 6, 11}, // "hello world"

	};
	
	const Tokenize_TestCase test_cases[] = {
		{"hello", 0, &expect_tokens[0], "Case 1 : hello"},
		{"%^", 0, &expect_tokens[1], "Case 2 : %^"},
		{"$", 0, &expect_tokens[2], "Case 3 : $"},
		{"&hhi", 0, &expect_tokens[3], "Case 4 : &hhi"},
		{"hello world", 0, &expect_tokens[4], "Case 5 : hello world (hello)"},
		{"hello world", 6, &expect_tokens[5], "Case 6 : hello world (world)"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_word, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}

TEST(Lexical_Tokenize, Word_Failed)
{
	const t_token expect_tokens[] = {
		{TK_DECLINED, "", 0, 0}, // "<|"
		{TK_DECLINED, "", 0, 0}, // " "
		{TK_DECLINED, "", 0, 0}, // ""
	};
	
	const Tokenize_TestCase test_cases[] = {
		{"<|", 0, &expect_tokens[0], "Case 1 : <|"},
		{" ", 0, &expect_tokens[1], "Case 2 : space"},
		{"", 0, &expect_tokens[2], "Case 3 : empty string"},
	};

	// execute the test
	test_runner_of_tokenize(
		ms_tokenize_word, 
		test_cases, 
		sizeof(test_cases) / sizeof(test_cases[0]));

}