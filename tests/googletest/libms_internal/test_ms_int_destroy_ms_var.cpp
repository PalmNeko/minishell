#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
};

// 開放できること。
TEST(ms_int_destroy_ms_var, basic)
{
    t_ms_var    *ms_var;

    ms_var = ms_int_create_ms_var("Hello", "World");
    ASSERT_NE(ms_var, nullptr);
    ms_int_destroy_ms_var(ms_var);
	ASSERT_TRUE(true);
}

// NULLが渡されても何もしないこと。
TEST(ms_int_destroy_ms_var, no_effect_if_argument_is_null)
{
    ms_int_destroy_ms_var(nullptr);
	ASSERT_TRUE(true);
}
