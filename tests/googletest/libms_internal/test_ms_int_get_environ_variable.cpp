#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
};

// 返ってきた値はNULLではないこと。
TEST(ms_int_get_environ_variable, must_not_null_pointer)
{
	ASSERT_NE(ms_int_get_environ_variable(), nullptr);
}
