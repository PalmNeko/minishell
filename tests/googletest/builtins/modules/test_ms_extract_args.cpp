#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
	#include "libms.h"
    #include "builtin_internal.h"
};

// オプションを飛ばすこと
TEST(ms_extract_args, remove_options)
{
	const char	*argv[] = {"command", "-opts", "arg1", "-arg2", NULL};
	char		**args;

	args = ms_extract_args((char *const *)argv);
	ASSERT_NE(args, nullptr);
	EXPECT_STREQ(args[0], "arg1");
	EXPECT_STREQ(args[1], "-arg2");
	EXPECT_EQ(args[2], nullptr);
	ms_destroy_ntp(args);
}

// --からは引数
TEST(ms_extract_args, double_hyphen)
{
	const char	*argv[] = {"command", "--", "-opts", "arg1", "-arg2", NULL};
	char		**args;

	args = ms_extract_args((char *const *)argv);
	ASSERT_NE(args, nullptr);
	EXPECT_STREQ(args[0], "-opts");
	EXPECT_STREQ(args[1], "arg1");
	EXPECT_STREQ(args[2], "-arg2");
	EXPECT_EQ(args[3], nullptr);
	ms_destroy_ntp(args);
}
