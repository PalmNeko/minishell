#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "lexer.h"
#include "ms_test.h"

};

TEST(Lexical_Token, CreateToken)
{
	// テストケースの定義
	struct				TestCase
	{
		t_token_type	type;
		const char		*token;
		int				start_pos;
		int				end_pos;
		const char		*description;
	};

	const struct TestCase test_cases[] = {
		{(t_token_type)TK_DECLINED, "???", 0, 3, "Declined token"},
		{(t_token_type)TK_IDENTIFY,	"identifier123", 0, 13, "Identifier token"},
		{(t_token_type)TK_WORD, "hello", 0, 5, "Word token"},
		{(t_token_type)TK_BLANK, " \t", 0, 2, "Blank token"},
		{(t_token_type)TK_NEWLINE, "\n", 0, 1, "Newline token"},
		{(t_token_type)TK_VARIABLE, "$PATH", 0, 5, "Variable token"},
		{(t_token_type)TK_PIPE, "|", 0, 1, "Pipe token"},
		{(t_token_type)TK_EQUALS, "=", 0, 1, "Equals token"},
		{(t_token_type)TK_SINGLE_QUOTE, "'", 0, 1, "Single quote token"},
		{(t_token_type)TK_DOUBLE_QUOTE, "\"", 0, 1, "Double quote token"},
		{(t_token_type)TK_REDIRECTION, "<", 0, 1, "Redirection input token"},
		{(t_token_type)TK_REDIRECTION, "<<", 0, 2, "Redirection heredoc token"},
		{(t_token_type)TK_REDIRECTION, ">", 0, 1, "Redirection output token"},
		{(t_token_type)TK_REDIRECTION, ">>", 0, 2, "Redirection append token"},
		{(t_token_type)TK_LEFT_PARENTHESIS, "(", 0, 1, "Left parenthesis token"},
		{(t_token_type)TK_RIGHT_PARENTHESIS, ")", 0, 1, "Right parenthesis token"},
		{(t_token_type)TK_LIST, "&&", 0, 2, "List AND token"},
		{(t_token_type)TK_LIST, "||", 0, 2, "List OR token"}
	};

	// 各テストケースを実行
	for (const auto &test_case : test_cases)
	{
		// テストの実行内容をメッセージとして出力
		SCOPED_TRACE(test_case.description);

		// トークンの作成
		t_token			*token = ms_create_token(test_case.type,
							test_case.token, test_case.start_pos,
							test_case.end_pos);

		// 基本的な検証
		ASSERT_NE(token, nullptr) << "Failed to create token for " << test_case.description;

		// 各フィールドの検証
		EXPECT_EQ(token->type,
			test_case.type) << "Incorrect token type for " << test_case.description;
		EXPECT_STREQ(token->token,
			test_case.token) << "Incorrect token string for " << test_case.description;
		EXPECT_EQ(token->start_pos,
			test_case.start_pos) << "Incorrect start position for " << test_case.description;
		EXPECT_EQ(token->end_pos,
			test_case.end_pos) << "Incorrect end position for " << test_case.description;

		// メモリの解放
		ms_lexical_analyze_destroy_token(token);
	}
}