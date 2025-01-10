#include <gtest/gtest.h>
#include <iostream>
#include <vector>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

void ms_lexical_analyze_destroy_token_wrapper(void *token)
{
	ms_lexical_analyze_destroy_token((t_token*)token);
}

//----------------------------------------
// テスト比較用ラッパー関数
//----------------------------------------
static void test_runner_of_ms_parse_quoted(
    t_syntax_node *expect,
    const char    *str,
    t_syntax_node *actual  // 実際のパース結果
)
{
    // 呼び出し元とは別に tokens を取得し直し、不要になったら破棄する
    t_token **tokens = ms_lexical_analyze(str);

    // ノードの型・位置を比較
    EXPECT_EQ(expect->type,      actual->type);
    EXPECT_EQ(expect->start_pos, actual->start_pos);
    EXPECT_EQ(expect->end_pos,   actual->end_pos);

    // “トークンを直接ぶら下げているか”
    if (expect->token) {
        ASSERT_TRUE(actual->token != NULL);
        EXPECT_EQ(expect->token->type,  actual->token->type);
        EXPECT_STREQ(expect->token->token, actual->token->token);
    }
    // “子ノードを持っているか”
    else {
        ASSERT_TRUE(expect->children != NULL);
        ASSERT_TRUE(actual->children != NULL);

        for (int i = 0; expect->children[i]; i++) {
            ASSERT_TRUE(actual->children[i] != NULL);

            EXPECT_EQ(expect->children[i]->type,      actual->children[i]->type);
            EXPECT_EQ(expect->children[i]->start_pos, actual->children[i]->start_pos);
            EXPECT_EQ(expect->children[i]->end_pos,   actual->children[i]->end_pos);

            // 子ノードにもトークンがあれば比較
            if (expect->children[i]->token && actual->children[i]->token) {
                EXPECT_EQ(expect->children[i]->token->type,  actual->children[i]->token->type);
                EXPECT_STREQ(expect->children[i]->token->token, actual->children[i]->token->token);
            }
        }
    }

    // テストに使用したノード等を破棄
    ms_syntax_node_destroy(actual);
    ms_destroy_ntp2(reinterpret_cast<void**>(tokens), ms_lexical_analyze_destroy_token_wrapper);
}

//----------------------------------------
// SY_DOUBLE_QUOTED_WORD の成功パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_Quoted, SY_DOUBLE_QUOTED_WORD_SUCCESS)
{
    const char *str = "\"word\"";

    // 期待値用トークンを作る
    t_token **expect_tokens = ms_lexical_analyze(str);

    // 期待ノードの子配列
    t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_double_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_double_quote(expect_tokens, 2);
	expect_children[3] = NULL;

    // 期待ノード本体 (SY_DOUBLE_QUOTED_WORD)
    t_syntax_node *expect = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD);
    expect->children  = expect_children;
    expect->start_pos = 0;
    expect->end_pos   = 3;

    // 実際のパース結果
    t_syntax_node *actual = ms_parse_double_quoted_word(expect_tokens, 0);

    // 比較
    test_runner_of_ms_parse_quoted(expect, str, actual);

    // 後片付け
    ms_syntax_node_destroy(expect);
    ms_destroy_ntp2((void**)expect_tokens, ms_lexical_analyze_destroy_token_wrapper);
}

//----------------------------------------
// SY_DOUBLE_QUOTED_WORD の失敗パターン
//----------------------------------------
TEST(Syntax_Analyze_Parse_Quoted, SY_DOUBLE_QUOTED_WORD_FAIL)
{
    const char *str = "\"word"; // 終了ダブルクォートがない

    // 実際の解析結果
    t_token **tokens = ms_lexical_analyze(str);
    t_syntax_node *actual = ms_parse_double_quoted_word(tokens, 0);

    // 期待ノード (SY_DECLINED)
    t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
    // “どのトークンで失敗したか” の情報を持たせるなら、以下のように
    expect->token = tokens[0];
    expect->start_pos = 0;
    expect->end_pos   = 1; 

    // 比較
    test_runner_of_ms_parse_quoted(expect, str, actual);

    // 後片付け
    ms_syntax_node_destroy(expect);
    // actual は test_runner 内で破棄済み
	ms_destroy_ntp2((void**)tokens, ms_lexical_analyze_destroy_token_wrapper);
}

//SY_SINGLE_QUOTED_WORD の成功パターン

TEST(Syntax_Analyze_Parse_Quoted, SY_SINGLE_QUOTED_WORD_SUCCESS)
{
	const char *str = "'word'";

	// 期待値用トークンを作る
	t_token **expect_tokens = ms_lexical_analyze(str);

	// 期待ノードの子配列
	t_syntax_node **expect_children = (t_syntax_node **)malloc(sizeof(t_syntax_node*) * 4);
	expect_children[0] = ms_parse_single_quote(expect_tokens, 0);
	expect_children[1] = ms_parse_all(expect_tokens, 1);
	expect_children[2] = ms_parse_single_quote(expect_tokens, 2);
	expect_children[3] = NULL;

	// 期待ノード本体 (SY_SINGLE_QUOTED_WORD)
	t_syntax_node *expect = ms_syntax_node_create(SY_SINGLE_QUOTED_WORD);
	expect->children  = expect_children;
	expect->start_pos = 0;
	expect->end_pos   = 3;

	// 実際のパース結果
	t_syntax_node *actual = ms_parse_single_quoted_word(expect_tokens, 0);

	// 比較
	test_runner_of_ms_parse_quoted(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	ms_destroy_ntp2(reinterpret_cast<void**>(expect_tokens), ms_lexical_analyze_destroy_token_wrapper);
}

//SY_SINGLE_QUOTED_WORD の失敗パターン
TEST(Syntax_Analyze_Parse_Quoted, SY_SINGLE_QUOTED_WORD_FAIL)
{
	const char *str = "'word"; // 終了シングルクォートがない

	// 実際の解析結果
	t_token **tokens = ms_lexical_analyze(str);
	t_syntax_node *actual = ms_parse_single_quoted_word(tokens, 0);

	// 期待ノード (SY_DECLINED)
	t_syntax_node *expect = ms_syntax_node_create(SY_DECLINED);
	// “どのトークンで失敗したか” の情報を持たせるなら、以下のように
	expect->token = tokens[0];
	expect->start_pos = 0;
	expect->end_pos   = 1; 

	// 比較
	test_runner_of_ms_parse_quoted(expect, str, actual);

	// 後片付け
	ms_syntax_node_destroy(expect);
	// actual は test_runner 内で破棄済み
	ms_destroy_ntp2(reinterpret_cast<void**>(tokens), ms_lexical_analyze_destroy_token_wrapper);
}