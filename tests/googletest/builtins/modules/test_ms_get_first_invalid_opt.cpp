#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// 無効なオプションを持っていなければ、NULLを返す。
TEST(ms_get_first_invalid_opt, null_if_has_no_invalid_opt)
{
	const char *args[] = {"command", "-n", NULL};

	EXPECT_EQ(ms_get_first_invalid_opt((char *const *)args, "n"), nullptr);
}

// 無効なオプションを持っていれば、そのアドレスを返す。
TEST(ms_get_first_invalid_opt, address_to_first_invalid_opt)
{
	const char *args[] = {"command", "-na", NULL};

	EXPECT_EQ(ms_get_first_invalid_opt((char *const *)args, "n"), &args[1][2]);
}

// --のあとのオプションは、無視する。
TEST(ms_get_first_invalid_opt, null_if_after_double_hyphen)
{
	const char *args[] = {"command", "--", "-a", NULL};

	EXPECT_EQ(ms_get_first_invalid_opt((char *const *)args, "n"), nullptr);
}

// 通常の引数の後のオプションは無視しする。
TEST(ms_get_first_invalid_opt, null_if_after_normal_argument)
{
	const char *args[] = {"command", "a", "-a", NULL};

	EXPECT_EQ(ms_get_first_invalid_opt((char *const *)args, "n"), nullptr);
}
