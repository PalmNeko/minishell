#include <gtest/gtest.h>

extern "C" {
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

TEST(ms_syntax_node_find_child, basic) {
	t_syntax_node	*command_node;
	t_syntax_node	*simple_command_node;
	t_token			**tokens;
	const char		*str;

	str = "echo hello > file\n echo\nEOF\n";
	tokens = ms_lexical_analyze(str);
	command_node = ms_syntax_analyze(tokens);

	simple_command_node = ms_syntax_node_find_child(command_node, SY_SIMPLE_COMMAND);
	EXPECT_EQ(simple_command_node->type, SY_SIMPLE_COMMAND);

	ms_syntax_node_destroy(command_node);
	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
}
