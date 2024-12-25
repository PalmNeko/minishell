#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "syntax_analyze.h"
};

TEST(Syntax_Analyze_Node_Create, SY_ALL)
{
	t_syntax_node *node = ms_syntax_node_create(SY_ALL, 0, 1);
	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->type, SY_ALL);
	EXPECT_EQ(node->start_pos, 0);
	EXPECT_EQ(node->end_pos, 5);
	free(node);
}