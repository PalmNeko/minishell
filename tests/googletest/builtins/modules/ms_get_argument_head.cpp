#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// 引数がなければ最後のアドレスを返す。
TEST(ms_get_argument_head, endaddress_if_no_argument)
{
	const char *args[] = {"command", "-n", NULL};

	EXPECT_EQ(ms_get_argument_head((char *const *)args, "n"), &args[2]);
}

// 無効なオプション引数があればそこのアドレスを返す。
TEST(ms_get_argument_head, true_if_has_no_invalid_opt)
{
	const char *args[] = {"command", "-n", NULL};

	EXPECT_EQ(ms_get_argument_head((char *const *)args, "a"), &args[1]);
}

// -- があればそこのアドレスを返す。
TEST(ms_get_argument_head, address_to_double_hyphen)
{
	const char *args[] = {"command", "-a", "--", "-a", NULL};

	EXPECT_EQ(ms_get_argument_head((char *const *)args, "a"), &args[2]);
}

// 通常の引数があればそれを返す。
TEST(ms_get_argument_head, address_to_normal_argument)
{
	const char *args[] = {"command", "-a", "a", NULL};

	EXPECT_EQ(ms_get_argument_head((char *const *)args, "a"), &args[2]);
}
