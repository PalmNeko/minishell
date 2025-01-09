#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
};

// 作成できること。
TEST(ms_int_create_ms_var, basic)
{
    t_ms_var    *ms_var;

    ms_var = ms_int_create_ms_var("Hello", "World");
    ASSERT_NE(ms_var, nullptr);
    EXPECT_STREQ(ms_var->name, "Hello");
    EXPECT_STREQ(ms_var->value, "World");
    ms_int_destroy_ms_var(ms_var);
}

// nameがNULLだったら、NULLを返して、errnoにEINVALが設定される。
TEST(ms_int_create_ms_var, error_if_name_is_null)
{
	errno = 0;
	ASSERT_EQ(ms_int_create_ms_var(NULL, "World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
}

// nameの長さが0だったら、NULLを返して、errnoにEINVALが設定される。
TEST(ms_int_create_ms_var, error_if_name_length_is_zero)
{
	errno = 0;
	ASSERT_EQ(ms_int_create_ms_var("", "World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
}

// nameに=が含まれていたら、NULLを返して、errnoにEINVALが設定される。
TEST(ms_int_create_ms_var, error_if_name_contain_equals)
{
	errno = 0;
	ASSERT_EQ(ms_int_create_ms_var("=", "World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
	errno = 0;
	ASSERT_EQ(ms_int_create_ms_var("av=sdf", "World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
}
