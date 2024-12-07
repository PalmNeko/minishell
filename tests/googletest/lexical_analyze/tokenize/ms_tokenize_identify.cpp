#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "lexer.h"
#include "ms_test.h"

};

// t_token ms_tokenize_some(const char *input, int pos);

struct				TestCase
	{
		const char		*input;
		int				pos;
		const char *description;
	};

struct TokenTestCase {
	t_token_type    type;
	const char      *token;
	int             start_pos;
	int             end_pos;
};

TEST(Tokenize, identify_test)
{
	// テストケースの定義
	const char* test_descprictions[] = {
		"succes_test 1 : \"_test\"",
		"succes_test 2 : \"&test\"",
		"succes_test 3 : \"tes3#t\"",
		"failed_test 1 : \"5test\"",
		"failed_test 2 : \"\"",
	};

	const struct TestCase test_cases[] = {
		{"_test", 0, test_descprictions[0]},
		{"&test", 1, test_descprictions[1]},
		{"3es3#t", 1, test_descprictions[2]},
		{"5test", 0, test_descprictions[3]},
		{"", 0, test_descprictions[4]},
	};

	const struct TokenTestCase collect_token_cases[] = {
		{(t_token_type)TK_IDENTIFY, "_test", 0, 5},
		{(t_token_type)TK_IDENTIFY, "test", 1, 5},
		{(t_token_type)TK_IDENTIFY, "es", 1, 3},
		{(t_token_type)TK_DECLINED, "", 0, 0},
		{(t_token_type)TK_DECLINED, "", 0, 0, },
	};

	// 各テストケースを実行
	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]);++i)
	{
		const auto &test_case = test_cases[i];
		const auto &collect_token_case = collect_token_cases[i];
		// テストの実行内容をメッセージとして出力
		SCOPED_TRACE(test_case.description);

		// オートマトンの事項
		t_token		*token = ms_tokenize_identify(test_case.input, test_case.pos);

		// 基本的な検証
		ASSERT_NE(token, nullptr) << "Failed to create token for " << test_case.description;

		// 各フィールドの検証
		EXPECT_EQ(token->type, collect_token_case.type);
		EXPECT_STREQ(token->token, collect_token_case.token);
		EXPECT_EQ(token->start_pos, collect_token_case.start_pos);
		EXPECT_EQ(token->end_pos, collect_token_case.end_pos);

		// メモリの解放
		ms_lexical_analyze_destroy_token(token);
	}
}