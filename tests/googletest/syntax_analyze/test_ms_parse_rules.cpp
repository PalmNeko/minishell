#include <gtest/gtest.h>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
};

t_syntax_node *ms_parse_tail_pipeline(t_token **tokens, int pos)
{
	t_syntax_node	*node;
	t_parse_func	funcs[][3] = {
		{ms_parse_pipe, NULL},
		{ms_parse_blank, NULL},
		{ms_parse_identify, ms_parse_word, NULL},
		{ms_parse_blank, NULL},
	};
	t_syntax_rule rules[] = {
        {EBNF_ONE, funcs[0], false},
        {EBNF_OPTION, funcs[1], false},
        {EBNF_ONE, funcs[2], false},
        {EBNF_OPTION, funcs[3], false},
    };
	t_syntax_rule *rules_ptr[] = {
		&rules[0],
		&rules[1],
		&rules[2],
		&rules[3],
		NULL
	};

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED, rules_ptr);
	return (node);
}

TEST(ms_parse_rules, comprehensive_success)
{
	t_token			**tokens;
	t_syntax_node	*node;
	t_parse_func	funcs[][3] = {
		{ms_parse_blank, NULL},
		{ms_parse_identify, ms_parse_word, NULL}, // 複数種類のテスト |
		{ms_parse_blank, NULL},
		{ms_parse_tail_pipeline, NULL},
	};
	t_syntax_rule rules[] = {
        {EBNF_OPTION, funcs[0], false}, // オプションのテスト 現れないとき
        {EBNF_ONE, funcs[1], false}, // 1回は必ず現れる必要がある
        {EBNF_OPTION, funcs[2], false}, // オプションのテスト 現れるとき
        {EBNF_REPEAT, funcs[3], true} // 繰り返しのテスト　展開時のテスト
    };
	t_syntax_rule *rules_ptr[] = {
		&rules[0],
		&rules[1],
		&rules[2],
		&rules[3],
		NULL
	};

	tokens = ms_lexical_analyze("test | #word | world");
	ASSERT_NE(tokens, nullptr);
	node = ms_parse_rules(tokens, 0, SY_PIPELINE, rules_ptr);

	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);

	if (node == NULL)
		FAIL();

	if (node->type != SY_PIPELINE)
	{
		ms_syntax_node_destroy(node);
		FAIL();
	}
	EXPECT_EQ(node->token, nullptr);
	EXPECT_EQ(node->children[0]->type, SY_IDENTIFY);
	EXPECT_EQ(node->children[1]->type, SY_BLANK);
	EXPECT_EQ(node->children[2]->type, SY_PIPE);
	EXPECT_EQ(node->children[3]->type, SY_BLANK);
	EXPECT_EQ(node->children[4]->type, SY_WORD);
	EXPECT_EQ(node->children[5]->type, SY_BLANK);
	EXPECT_EQ(node->children[6]->type, SY_PIPE);
	EXPECT_EQ(node->children[7]->type, SY_BLANK);
	EXPECT_EQ(node->children[8]->type, SY_IDENTIFY);
	EXPECT_EQ(node->children[9], nullptr);

	EXPECT_EQ(node->children[0]->children, nullptr);
	EXPECT_EQ(node->children[1]->children, nullptr);
	EXPECT_EQ(node->children[2]->children, nullptr);
	EXPECT_EQ(node->children[3]->children, nullptr);
	EXPECT_EQ(node->children[4]->children, nullptr);
	EXPECT_EQ(node->children[5]->children, nullptr);
	EXPECT_EQ(node->children[6]->children, nullptr);
	EXPECT_EQ(node->children[7]->children, nullptr);

	EXPECT_STREQ(node->children[0]->token->token, "test");
	EXPECT_STREQ(node->children[1]->token->token, " ");
	EXPECT_STREQ(node->children[2]->token->token, "|");
	EXPECT_STREQ(node->children[3]->token->token, " ");
	EXPECT_STREQ(node->children[4]->token->token, "#word");
	EXPECT_STREQ(node->children[5]->token->token, " ");
	EXPECT_STREQ(node->children[6]->token->token, "|");
	EXPECT_STREQ(node->children[7]->token->token, " ");
	EXPECT_STREQ(node->children[8]->token->token, "world");

	ms_syntax_node_destroy(node);
}

TEST(ms_parse_rules, EBNF_ONE_declined)
{
	t_token			**tokens;
	t_syntax_node	*node;
	t_parse_func	funcs[][3] = {
		{ms_parse_identify, NULL},
	};
	t_syntax_rule rules[] = {
        {EBNF_ONE, funcs[0], false}, // 1回は必ず現れる必要がある
    };
	t_syntax_rule *rules_ptr[] = {
		&rules[0],
		NULL
	};

	tokens = ms_lexical_analyze("#test");
	ASSERT_NE(tokens, nullptr);
	node = ms_parse_rules(tokens, 0, SY_IDENTIFY, rules_ptr);

	ms_destroy_ntp2((void **)tokens,  ms_destroy_token_wrapper);

	ASSERT_NE(node, nullptr);

	ASSERT_EQ(node->type, SY_DECLINED);

	ms_syntax_node_destroy(node);
}
