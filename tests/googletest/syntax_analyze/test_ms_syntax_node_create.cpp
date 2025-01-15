#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "syntax_analyze.h"
};

TEST(Syntax_Analyze, Node_Create)
{
	t_syntax_node *node = ms_syntax_node_create(SY_ALL);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_ALL);
	free(node);
}
