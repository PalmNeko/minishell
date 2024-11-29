#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// -から始まれば、trueを返す。
TEST(ms_is_option, true_if_start_hyphen)
{
	EXPECT_TRUE(ms_is_option("-123"));
}

// -以外から始まれば、falseを返す。
TEST(ms_is_option, false_if_start_not_hyphen)
{
	EXPECT_FALSE(ms_is_option("123"));
}

// -のみの場合、falseを返す。
TEST(ms_is_option, false_if_only_hyphen)
{
	EXPECT_FALSE(ms_is_option("-"));
}

// --の場合、falseを返す。
TEST(ms_is_option, false_if_double_hyphen)
{
	EXPECT_FALSE(ms_is_option("--"));
}

// --の後に文字が続く場合、trueを返す。
TEST(ms_is_option, true_if_double_hyphen)
{
	EXPECT_TRUE(ms_is_option("--a"));
}
