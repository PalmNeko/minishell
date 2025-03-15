#include <gtest/gtest.h>

extern "C"
{
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
};

void test_runner_of_ms_parse(t_syntax_node *expect, const char *str, t_syntax_node *actual);
void ms_destroy_token_wrapper(void *token);

TEST(ms_syntax_analyze_internal, ms_parse_symbol_item)
{
	t_token **tokens = ms_lexical_analyze("exam=hoge");
	t_parse_func g_ms_parse_simple_command_func_list[3] = {
		ms_parse_assignment_command,
		ms_parse_word_list,
		NULL
	};
	t_syntax_node *node = ms_parse_symbol_item(tokens, 0, g_ms_parse_simple_command_func_list);
	EXPECT_EQ(node->type, SY_ASSIGNMENT_COMMAND);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 3);
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}