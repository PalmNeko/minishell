#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <errno.h>
	#include <string.h>
};

// 設定された変数がunsetされること
TEST(ms_unsetenv, can_set_new_environ)
{
	ASSERT_EQ(ms_setenv("NEW_VALUE", "123", 1), 0);
	ms_unsetenv("NEW_VALUE");
	EXPECT_EQ(ms_getenv("NEW_VALUE"), nullptr);
}


// nameがNULLだったら、-1を返して、errnoにEINVALが設定される。
TEST(ms_unsetenv, error_if_name_is_null)
{
	errno = 0;
	EXPECT_EQ(ms_unsetenv(NULL), -1);
	EXPECT_EQ(errno, EINVAL);
}

// nameの長さが0だったら、-1を返して、errnoにEINVALが設定される。
TEST(ms_unsetenv, error_if_name_length_is_zero)
{
	errno = 0;
	EXPECT_EQ(ms_unsetenv(""), -1);
	EXPECT_EQ(errno, EINVAL);
}

// nameに=が含まれていたら、-1を返して、errnoにEINVALが設定される。
TEST(ms_unsetenv, error_if_name_contain_equals)
{
	errno = 0;
	EXPECT_EQ(ms_unsetenv("="), -1);
	EXPECT_EQ(errno, EINVAL);
	errno = 0;
	EXPECT_EQ(ms_unsetenv("av=sdf"), -1);
	EXPECT_EQ(errno, EINVAL);
}
