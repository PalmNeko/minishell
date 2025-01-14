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

void test_runner_of_ms_parse(
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
