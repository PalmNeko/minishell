#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
	#include <errno.h>
};

// 正しい使い方をしたときに生成されること。
TEST(ms_int_generate_ms_var_from_text, basic)
{
    t_ms_var    *ms_var;

    ms_var = ms_int_generate_ms_var_from_text("Hello=World");
    ASSERT_NE(ms_var, nullptr);
    EXPECT_STREQ(ms_var->name, "Hello");
    EXPECT_STREQ(ms_var->value, "World");
    ms_int_destroy_ms_var(ms_var);
}

// nameの長さが0だったら、NULLを返して、errnoにEINVALが設定される。
TEST(ms_int_generate_ms_var_from_text, error_if_name_length_is_zero)
{
	errno = 0;
	ASSERT_EQ(ms_int_generate_ms_var_from_text("=World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
}

// textに=が含まれていなかったら、NULLを返して、errnoにEINVALが設定される。
TEST(ms_int_generate_ms_var_from_text, error_if_name_contain_no_equals)
{
	errno = 0;
	ASSERT_EQ(ms_int_generate_ms_var_from_text("World"), nullptr);
	EXPECT_EQ(errno, EINVAL);
}
