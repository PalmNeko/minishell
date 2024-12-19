#include <gtest/gtest.h>
#include <iostream>
#include <vector>

extern "C"
{
	#include "lexer.h"
};

struct				Lexical_TestCase
{
	const char		*input;
	std::vector<t_token>	expect;
	const char		*description;
};

void test_runner_of_lexical_analize(
	const Lexical_TestCase *test_cases,
	size_t size
);

TEST(LexicalAnalyseTest, SingleInput) {
	// test_case_list
	Lexical_TestCase test_case_list[] = {
		{
			// hoge%
			"hoge%",
			{
				{TK_WORD, "hoge%", 0, 5}
			},
			"Case 1 : Single word"
		},
		{
			// _hoge
			"_hoge",
			{
				{TK_IDENTIFY, "_hoge", 0, 5}
			},
			"Case 2 : Single identify"
		},
		{
			// )
			")",
			{
				{TK_RIGHT_PARENTHESIS, ")", 0, 1}
			},
			"Case 3 : Single right parenthesis"
		},
		{
			// (
			"(",
			{
				{TK_LEFT_PARENTHESIS, "(", 0, 1}
			},
			"Case 4 : Single left parenthesis"
		},
		{
			// \n
			"\n",
			{
				{TK_NEWLINE, "\n", 0, 1}
			},
			"Case 5 : Single newline"
		},
		{
			// =
			"=",
			{
				{TK_EQUALS, "=", 0, 1}
			},
			"Case 6 : Single equals"
		},
		{
			// \t
			" \t ",
			{
				{TK_BLANK, " \t ", 0, 3}
			},
			"Case 7 : Single blank"
		},
		{
			// &&
			"&&",
			{
				{TK_LIST, "&&", 0, 2}
			},
			"Case 8 : Single list"
		},
		{
			// |
			"|",
			{
				{TK_PIPE, "|", 0, 1}
			},
			"Case 9 : Single pipe"
		},
		{
			// "
			"\"",
			{
				{TK_DOUBLE_QUOTE, "\"", 0, 1}
			},
			"Case 10 : Single double quote"
		},
		{
			// '
			"'",
			{
				{TK_SINGLE_QUOTE, "'", 0, 1}
			},
			"Case 11 : Single single quote"
		},
		{
			// >
			">",
			{
				{TK_REDIRECTION, ">", 0, 1}
			},
			"Case 12 : Single redirection(>)"
		},
		{
			// $test
			"$test",
			{
				{TK_VARIABLE, "$test", 0, 5}
			},
			"Case 13 : Single variable"
		},
	};

	test_runner_of_lexical_analize(
		test_case_list,
		sizeof(test_case_list) / sizeof(test_case_list[0])
	);
}

TEST(LexicalAnalyseTest, CompareCategoryPriorty){
	// 
	Lexical_TestCase test_case_list[] = {
		{
			// "Hello World"
			"\"Hello World\"",
			{
				{TK_DOUBLE_QUOTE, "\"", 0, 1},
				{TK_IDENTIFY, "Hello", 1, 6},
				{TK_BLANK, " ", 6, 7},
				{TK_IDENTIFY, "World", 7, 12},
				{TK_DOUBLE_QUOTE, "\"", 12, 13}
			},
			"Case 1 : Single word"
		}
	};

	test_runner_of_lexical_analize(
		test_case_list,
		sizeof(test_case_list) / sizeof(test_case_list[0])
		);

}

void test_runner_of_lexical_analize(
	const Lexical_TestCase *test_cases,
	size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		const auto &test_case = test_cases[i];
		// output the test description
		SCOPED_TRACE(test_case.description);

		t_token **tokens = ms_lexical_analyze(test_case.input);

		// basic validation (token creation)
		ASSERT_NE(tokens,nullptr) << "Failed to create token for " << test_case.description;

		// validation of each field of the token
		for (size_t j = 0; tokens[j] != NULL; j++)
		{
			EXPECT_EQ(tokens[j]->type, test_case.expect[j].type) << "Incorrect token type for " << test_case.description;
			EXPECT_STREQ(tokens[j]->token, test_case.expect[j].token) << "Incorrect token string for " << test_case.description;
			EXPECT_EQ(tokens[j]->start_pos, test_case.expect[j].start_pos) << "Incorrect start position for " << test_case.description;
			EXPECT_EQ(tokens[j]->end_pos, test_case.expect[j].end_pos) << "Incorrect end position for " << test_case.description;
		}
		for (size_t j = 0; tokens[j] != NULL; j++)
		{
			ms_lexical_analyze_destroy_token(tokens[j]);
		}
		free(tokens);
	}
}
	