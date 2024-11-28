#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <errno.h>
	#include <string.h>
};

// 新しい変数を設定できる。
TEST(ms_setenv, can_set_new_environ)
{
	ms_unsetenv("NEW_ENVIRON");
	ASSERT_EQ(ms_setenv("NEW_ENVIRON", "ms_setenv", 0), 0);
	EXPECT_STREQ(ms_getenv("NEW_ENVIRON"), "ms_setenv");
}

// 変数を上書き設定できる。
TEST(ms_setenv, can_overwrite)
{
	ms_unsetenv("NEW_ENVIRON");
	ASSERT_EQ(ms_setenv("NEW_ENVIRON", "ms_setenv", 0), 0);
	ASSERT_EQ(ms_setenv("NEW_ENVIRON", "ms_woiej", 1), 0);
	EXPECT_STREQ(ms_getenv("NEW_ENVIRON"), "ms_woiej");
}

// nameがNULLだったら、-1を返して、errnoにEINVALが設定される。
TEST(ms_setenv, error_if_name_is_null)
{
	errno = 0;
	EXPECT_EQ(ms_setenv(NULL, "ms_setenv", 0), -1);
	EXPECT_EQ(errno, EINVAL);
}

// nameの長さが0だったら、-1を返して、errnoにEINVALが設定される。
TEST(ms_setenv, error_if_name_length_is_zero)
{
	errno = 0;
	EXPECT_EQ(ms_setenv("", "ms_setenv", 0), -1);
	EXPECT_EQ(errno, EINVAL);
}

// nameに=が含まれていたら、-1を返して、errnoにEINVALが設定される。
TEST(ms_setenv, error_if_name_contain_equals)
{
	errno = 0;
	EXPECT_EQ(ms_setenv("=", "ms_setenv", 0), -1);
	EXPECT_EQ(errno, EINVAL);
	errno = 0;
	EXPECT_EQ(ms_setenv("av=sdf", "ms_setenv", 0), -1);
	EXPECT_EQ(errno, EINVAL);
}
