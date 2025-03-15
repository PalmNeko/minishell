
#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
}

TEST(ms_compare_heredoc_input, basic)
{
	EXPECT_TRUE(ms_compare_heredoc_input("abc\n", "abc\n"));
	EXPECT_TRUE(ms_compare_heredoc_input("abc", "abc\n"));
	EXPECT_TRUE(ms_compare_heredoc_input("abc\n", "abc"));
	EXPECT_TRUE(ms_compare_heredoc_input("abc", "abc"));
	EXPECT_FALSE(ms_compare_heredoc_input("abca", "abcb"));
	EXPECT_FALSE(ms_compare_heredoc_input("abc", " abc"));
	EXPECT_FALSE(ms_compare_heredoc_input("abc", "abc "));
	EXPECT_FALSE(ms_compare_heredoc_input("abc", " abc "));
}
