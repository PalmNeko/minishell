#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

TEST(ms_lsa_get_child_node, basic) {
	t_syntax_node	*command_node;
	t_syntax_node	*user_input_node;
	t_syntax_node	*simple_command_node;
	t_token			**tokens;
	const char		*str;

	str = "echo hello > file\n echo\nEOF\n";
	tokens = ms_lexical_analyze(str);
	command_node = ms_syntax_analyze(tokens);

	user_input_node = ms_syntax_node_get_child(command_node, SY_USER_INPUT);
	EXPECT_EQ(user_input_node->type, SY_USER_INPUT);

	simple_command_node = ms_syntax_node_find_child(command_node, SY_SIMPLE_COMMAND);
	user_input_node = ms_syntax_node_get_child(simple_command_node, SY_WORD_LIST);
	EXPECT_EQ(user_input_node->type, SY_WORD_LIST);

	ms_syntax_node_destroy(command_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}
