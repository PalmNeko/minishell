#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// 対象のオプションを持っていれば、trueを返す。
TEST(ms_has_opt, true_if_has_target_valid_opt)
{
	const char *args[] = {"command", "-n", NULL};

	EXPECT_TRUE(ms_has_opt((char *const *)args, 'n', "n"));
}

// 対象のオプションを持っていれば、falseを返す。
TEST(ms_has_opt, false_if_has_target_valid_opt)
{
	const char *args[] = {"command", "-n", NULL};

	EXPECT_FALSE(ms_has_opt((char *const *)args, 'n', "a"));
}

// 有効じゃないオプションの後のオプションは無視し、falseを返す。
TEST(ms_has_opt, false_if_after_invalid_option)
{
	const char *args[] = {"command", "-na", "-n", NULL};

	EXPECT_FALSE(ms_has_opt((char *const *)args, 'n', "n"));
}

// --のあとのオプションは、falseを返す。
TEST(ms_has_opt, false_if_after_double_hyphen)
{
	const char *args[] = {"command", "--", "-n", NULL};

	EXPECT_FALSE(ms_has_opt((char *const *)args, 'n', "n"));
}

// 通常の引数の後のオプションは無視し、falseを返す。
TEST(ms_has_opt, false_if_after_normal_argument)
{
	const char *args[] = {"command", "a", "-n", NULL};

	EXPECT_FALSE(ms_has_opt((char *const *)args, 'n', "n"));
}
