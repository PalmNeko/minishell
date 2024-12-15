#include "./ms_tokenize_test_types.h"
#include "gtest/gtest.h"
#include <functional>

extern "C"
{
#include "lexer.h"

};

// ms_tokenize_someをラップしてテストを実行するランナー
void	ms_tokenize_test_runner(
	const std::function<t_token *(const char *, int) > &ms_tokenize_func, 
	const Tokenize_TestCase *test_cases,
	size_t size
){
	for (size_t i = 0; i < size; ++i)
	{
		const auto &test_case = test_cases[i];
		// output the test description
		SCOPED_TRACE(test_case.description);

		t_token *token = ms_tokenize_func(test_case.input, test_case.pos);

		// basic validation (token creation)
		ASSERT_NE(token,nullptr) << "Failed to create token for " << test_case.description;

		// validation of each field of the token
		ASSERT_EQ(token->type, test_case.expect->type) << "type";
		ASSERT_STREQ(token->token, test_case.expect->token) << "token";
		ASSERT_EQ(token->start_pos, test_case.expect->start_pos) << "start_pos";
		ASSERT_EQ(token->end_pos, test_case.expect->end_pos) << "end_pos";

		// release the token
		ms_lexical_analyze_destroy_token(token);
	}
}