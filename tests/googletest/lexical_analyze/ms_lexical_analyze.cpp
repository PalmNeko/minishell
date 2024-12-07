// #include "CaptureFd.hpp"
// #include <gtest/gtest.h>
// #include <iostream>

// extern "C"
// {
// 	"ms_lexical_testcase.h"
// 	"lexer.h"
// 	"lexer_types.h"
// 	"ms_test.h"
// }

// // single test
// // Lexer_test
// TEST(Lexer_test, Simple_command_test)
// {
// 	t_token			token;
// 	t_token_type	token_type;
// 	const int		result[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// 	for (auto i = 0; i < sizeof(result) / sizeof(result[0]); i++)
// 	{
// 		token = ms_lexical_analyze(test_case_simple[i][0]);
// 		EXPECT_EQ(token.type, result[i]);
// 	}
// }
