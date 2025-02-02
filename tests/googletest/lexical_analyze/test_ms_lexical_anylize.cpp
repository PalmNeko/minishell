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

TEST(LexicalAnalyzeTest, SingleInput) {
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
			"Case 8 : Single list(&&)"
		},
		{
			// ||
			"||",
			{
				{TK_LIST, "||", 0, 2}
			},
			"Case 9 : Single list(||)"
		},
		{
			// |
			"|",
			{
				{TK_PIPE, "|", 0, 1}
			},
			"Case 10 : Single pipe"
		},
		{
			// "
			"\"",
			{
				{TK_DOUBLE_QUOTE, "\"", 0, 1}
			},
			"Case 11 : Single double quote"
		},
		{
			// '
			"'",
			{
				{TK_SINGLE_QUOTE, "'", 0, 1}
			},
			"Case 12 : Single single quote"
		},
		{
			// <
			"<",
			{
				{TK_REDIRECTION, "<", 0, 1}
			},
			"Case 13 : Single redirection(<)"
		},
		{
			// <<
			"<<",
			{
				{TK_REDIRECTION, "<<", 0, 2}
			},
			"Case 14 : Single redirection(<<)"
		},
		{
			// >
			">",
			{
				{TK_REDIRECTION, ">", 0, 1}
			},
			"Case 15 : Single redirection(>)"
		},
		{
			// >>
			">>",
			{
				{TK_REDIRECTION, ">>", 0, 2}
			},
			"Case 16 : Single redirection(>>)"
		},
		{
			// $PATH
			"$PATH",
			{
				{TK_VARIABLE, "$PATH", 0, 5}
			},
			"Case 17 : Single variable"
		}
	};


	test_runner_of_lexical_analize(
		test_case_list,
		sizeof(test_case_list) / sizeof(test_case_list[0])
	);
}

TEST(LexicalAnalyzeTest, MultipleInput_Simple) {
	Lexical_TestCase test_case_list[] = {
		{
			"\"Hello World\"",
			{
				{TK_DOUBLE_QUOTE, "\"", 0, 1},
				{TK_IDENTIFY, "Hello", 1, 6},
				{TK_BLANK, " ", 6, 7},
				{TK_IDENTIFY, "World", 7, 12},
				{TK_DOUBLE_QUOTE, "\"", 12, 13}
			},
			"Case 1 : with double quote"
		},
		{
			"\'Hello World\'",
			{
				{TK_SINGLE_QUOTE, "\'", 0, 1},
				{TK_IDENTIFY, "Hello", 1, 6},
				{TK_BLANK, " ", 6, 7},
				{TK_IDENTIFY, "World", 7, 12},
				{TK_SINGLE_QUOTE, "\'", 12, 13}
			},
			"Case 2 : with single quote"
		},
		{
			"echo hello > file.txt",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hello", 5, 10},
				{TK_BLANK, " ", 10, 11},
				{TK_REDIRECTION, ">", 11, 12},
				{TK_BLANK, " ", 12, 13},
				{TK_WORD, "file.txt", 13, 21}
			},
			"Case 3 : with redirection(>)"
		},
		{
			"echo Hello >> file.txt",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "Hello", 5, 10},
				{TK_BLANK, " ", 10, 11},
				{TK_REDIRECTION, ">>", 11, 13},
				{TK_BLANK, " ", 13, 14},
				{TK_WORD, "file.txt", 14, 22}
			},
			"Case 4 : with redirection(>>)"
		},
		{
			"cat << EOF",
			{
				{TK_IDENTIFY, "cat", 0, 3},
				{TK_BLANK, " ", 3, 4},
				{TK_REDIRECTION, "<<", 4, 6},
				{TK_BLANK, " ", 6, 7},
				{TK_IDENTIFY, "EOF", 7, 10}
			},
			"Case 5 : with redirection(<<)"
		},
		{
			"cat < infile.txt",
			{
				{TK_IDENTIFY, "cat", 0, 3},
				{TK_BLANK, " ", 3, 4},
				{TK_REDIRECTION, "<", 4, 5},
				{TK_BLANK, " ", 5, 6},
				{TK_WORD, "infile.txt", 6, 16}
			},
			"Case 6 : with redirection(<)"
		},
		{
			"echo hoge | cat",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hoge", 5, 9},
				{TK_BLANK, " ", 9, 10},
				{TK_PIPE, "|", 10, 11},
				{TK_BLANK, " ", 11, 12},
				{TK_IDENTIFY, "cat", 12, 15}
			},
			"Case 7 : with pipe"
		},
		{
			"echo hoge || cat",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hoge", 5, 9},
				{TK_BLANK, " ", 9, 10},
				{TK_LIST, "||", 10, 12},
				{TK_BLANK, " ", 12, 13},
				{TK_IDENTIFY, "cat", 13, 16}
			},
			"Case 8 : with list(||)"
		},
		{
			"echo hoge && cat",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hoge", 5, 9},
				{TK_BLANK, " ", 9, 10},
				{TK_LIST, "&&", 10, 12},
				{TK_BLANK, " ", 12, 13},
				{TK_IDENTIFY, "cat", 13, 16}
			},
			"Case 9 : with list(&&)"
		},
		{
			"(echo hoge)",
			{
				{TK_LEFT_PARENTHESIS, "(", 0, 1},
				{TK_IDENTIFY, "echo", 1, 5},
				{TK_BLANK, " ", 5, 6},
				{TK_IDENTIFY, "hoge", 6, 10},
				{TK_RIGHT_PARENTHESIS, ")", 10, 11}
			},
			"Case 10 : with parenthesis"
		},
		{
			"echo hoge\n",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hoge", 5, 9},
				{TK_NEWLINE, "\n", 9, 10}
			},
			"Case 11 : with newline"
		},
		{
			"echo $hoge",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_VARIABLE, "$hoge", 5, 10}
			},
			"Case 12 : with variable"
		},
		{
			"a=b",
			{
				{TK_IDENTIFY, "a", 0, 1},
				{TK_EQUALS, "=", 1, 2},
				{TK_IDENTIFY, "b", 2, 3}
			},
			"Case 13 : with equals"
		},
		{
			"|||",
			{
				{TK_LIST, "||", 0, 2},
				{TK_PIPE, "|", 2, 3}
			},
			"Case 14 : |||"
		}
	};

	test_runner_of_lexical_analize(test_case_list,sizeof(test_case_list) / sizeof(test_case_list[0]));

}

TEST(LexicalAnalyseTest, MultipleInput_Complex) {
	Lexical_TestCase test_case_list[] = {
		{
			"echo \"Hello World\" >  file.txt",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_DOUBLE_QUOTE, "\"", 5, 6},
				{TK_IDENTIFY, "Hello", 6, 11},
				{TK_BLANK, " ", 11, 12},
				{TK_IDENTIFY, "World", 12, 17},
				{TK_DOUBLE_QUOTE, "\"", 17, 18},
				{TK_BLANK, " ", 18, 19},
				{TK_REDIRECTION, ">", 19, 20},
				{TK_BLANK, "  ", 20, 22},
				{TK_WORD, "file.txt", 22, 30}
			},
			"Case 1 : echo \"Hello World\" > file.txt"
		},
		{
			"echo \"Hello World\" >> file.txt",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_DOUBLE_QUOTE, "\"", 5, 6},
				{TK_IDENTIFY, "Hello", 6, 11},
				{TK_BLANK, " ", 11, 12},
				{TK_IDENTIFY, "World", 12, 17},
				{TK_DOUBLE_QUOTE, "\"", 17, 18},
				{TK_BLANK, " ", 18, 19},
				{TK_REDIRECTION, ">>", 19, 21},
				{TK_BLANK, " ", 21, 22},
				{TK_WORD, "file.txt", 22, 30}
			},
			"Case 2 : echo \"Hello World\" >> file.txt"
		},
		{
			"cat << EOF > file.txt",
			{
				{TK_IDENTIFY, "cat", 0, 3},
				{TK_BLANK, " ", 3, 4},
				{TK_REDIRECTION, "<<", 4, 6},
				{TK_BLANK, " ", 6, 7},
				{TK_IDENTIFY, "EOF", 7, 10},
				{TK_BLANK, " ", 10, 11},
				{TK_REDIRECTION, ">", 11, 12},
				{TK_BLANK, " ", 12, 13},
				{TK_WORD, "file.txt", 13, 21}
			},
			"Case 3 : cat << EOF > file.txt"
		},
		{
			"echo hoge || cat > file.txt",
			{
				{TK_IDENTIFY, "echo", 0, 4},
				{TK_BLANK, " ", 4, 5},
				{TK_IDENTIFY, "hoge", 5, 9},
				{TK_BLANK, " ", 9, 10},
				{TK_LIST, "||", 10, 12},
				{TK_BLANK, " ", 12, 13},
				{TK_IDENTIFY, "cat", 13, 16},
				{TK_BLANK, " ", 16, 17},
				{TK_REDIRECTION, ">", 17, 18},
				{TK_BLANK, " ", 18, 19},
				{TK_WORD, "file.txt", 19, 27}
			},
			"Case 4 : echo hoge || cat > file.txt"
		},
		{
			"(echo hoge) > file.txt",
			{
				{TK_LEFT_PARENTHESIS, "(", 0, 1},
				{TK_IDENTIFY, "echo", 1, 5},
				{TK_BLANK, " ", 5, 6},
				{TK_IDENTIFY, "hoge", 6, 10},
				{TK_RIGHT_PARENTHESIS, ")", 10, 11},
				{TK_BLANK, " ", 11, 12},
				{TK_REDIRECTION, ">", 12, 13},
				{TK_BLANK, " ", 13, 14},
				{TK_WORD, "file.txt", 14, 22}
			},
			"Case 5 : (echo hoge) > file.txt"
		},
		{
			"a|b(c||d&&e)f\n= hoge&&|||\"\'\'><$ $hoge",
			{
				{TK_IDENTIFY, "a", 0, 1},
				{TK_PIPE, "|", 1, 2},
				{TK_IDENTIFY, "b", 2, 3},
				{TK_LEFT_PARENTHESIS, "(", 3, 4},
				{TK_IDENTIFY, "c", 4, 5},
				{TK_LIST, "||", 5, 7},
				{TK_IDENTIFY, "d", 7, 8},
				{TK_LIST, "&&", 8, 10},
				{TK_IDENTIFY, "e", 10, 11},
				{TK_RIGHT_PARENTHESIS, ")", 11, 12},
				{TK_IDENTIFY, "f", 12, 13},
				{TK_NEWLINE, "\n", 13, 14},
				{TK_EQUALS, "=", 14, 15},
				{TK_BLANK, " ", 15, 16},
				{TK_IDENTIFY, "hoge", 16, 20},
				{TK_LIST, "&&", 20, 22},
				{TK_LIST, "||", 22, 24},
				{TK_PIPE, "|", 24, 25},
				{TK_DOUBLE_QUOTE, "\"", 25, 26},
				{TK_SINGLE_QUOTE, "\'", 26, 27},
				{TK_SINGLE_QUOTE, "\'", 27, 28},
				{TK_REDIRECTION, ">", 28, 29},
				{TK_REDIRECTION, "<", 29, 30},
				{TK_WORD, "$", 30, 31},
				{TK_BLANK, " ", 31, 32},
				{TK_VARIABLE, "$hoge", 32, 37}
			},
			"Case 6 : a|b(c||d&&e)f\n= hoge&&|||\"\'\'><$$hoge"
		}
	};

	test_runner_of_lexical_analize(test_case_list,sizeof(test_case_list) / sizeof(test_case_list[0]));
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
	