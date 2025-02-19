#include <gtest/gtest.h>
#include <iostream>
#include <vector>

extern "C"
{
	#include "input.h"
};


TEST(ms_set_delimita_list, basic_usage)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "hoge << EOF ; fuga << EOC";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 2);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, "EOF");
	EXPECT_STREQ((char *)heredoc.delimita_list->next->content, "EOC");
	EXPECT_EQ(heredoc.delimita_list->next->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, null_string)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 0);
	EXPECT_EQ(heredoc.delimita_list, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, delimiter_includes_sign)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "<<-EOF";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 1);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, "-EOF");
	EXPECT_EQ(heredoc.delimita_list->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, quoted_with_double_quote)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "<<\"E\"\"\"\"OF\"";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 1);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, "EOF");
	EXPECT_EQ(heredoc.delimita_list->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, single_quote_in_double_quoted)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "<< \"E''OF\"";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 1);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, "E''OF");
	EXPECT_EQ(heredoc.delimita_list->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, single_quoted)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "<< '\"EOF\"'";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 1);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, "\"EOF\"");
	EXPECT_EQ(heredoc.delimita_list->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, include_space)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "<< \" EOF \"'";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 1);
	ASSERT_NE(heredoc.delimita_list, nullptr);
	EXPECT_STREQ((char *)heredoc.delimita_list->content, " EOF ");
	EXPECT_EQ(heredoc.delimita_list->next, nullptr);
	ms_finalize_heredoc(&heredoc);
}

TEST(ms_set_delimita_list, no_delimiter)
{
	t_heredoc	heredoc;
	int			ret;
	char		input[] = "hoge < < EOF";

	ms_init_heredoc(&heredoc);
	ret = ms_set_delimita_list(&heredoc, input);
	EXPECT_EQ(ret, 0);
	EXPECT_EQ(heredoc.delimita_count, 0);
	EXPECT_EQ(heredoc.delimita_list, nullptr);
	ms_finalize_heredoc(&heredoc);
}
