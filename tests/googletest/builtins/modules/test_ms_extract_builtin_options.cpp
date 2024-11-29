#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin_internal.h"
};

// -から始まるものをオプションとし、それ以外の引数がある。ただし、`--`はオプションとそれ以外の引数

// それ以外の引数までをオプションとして扱う。
TEST(ms_extract_opts, until_argument)
{
	char	*options;
	char *const	*args = (char *const[]){"command", "-abds", "argument", "-dummy", NULL};

	options = ms_extract_opts(args);
	ASSERT_NE(options, nullptr);
	EXPECT_STREQ(options, "abds");
	free(options);
}

// `--`までをオプションとして扱う。
TEST(ms_extract_opts, until_double_hyphen)
{
	char		*options;
	char *const	*args = (char *const[]){"command", "-abds-", "--", "-dummy", NULL};

	options = ms_extract_opts(args);
	ASSERT_NE(options, nullptr);
	EXPECT_STREQ(options, "abds-");
	free(options);
}

// 重複は削除する。
TEST(ms_extract_opts, remove_duplicated)
{
	char		*options;
	char *const	*args = (char *const[]){"command", "-aaaa", "--", "-dummy", NULL};

	options = ms_extract_opts(args);
	ASSERT_NE(options, nullptr);
	EXPECT_STREQ(options, "a");
	free(options);
}

// オプションがない間は、空文字列を返す。
TEST(ms_extract_opts, return_empty_if_has_no_opts)
{
	char		*options;
	char *const	*args = (char *const[]){"command", "", "--", "-dummy", NULL};

	options = ms_extract_opts(args);
	ASSERT_NE(options, nullptr);
	EXPECT_STREQ(options, "");
	free(options);
}
