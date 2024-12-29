#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
	#include <stdlib.h>
};

// nameがNULLだった場合は、falseを返すこと。
TEST(ms_int_validate_env_name, false_if_null_pointer)
{
	EXPECT_FALSE(ms_int_validate_env_name(NULL));
}

// nameが""だった場合は、falseを返すこと。
TEST(ms_int_validate_env_name, false_if_length_is_zero)
{
	EXPECT_FALSE(ms_int_validate_env_name(""));
}

// nameが"="だった場合は、falseを返すこと。
TEST(ms_int_validate_env_name, false_if_str_is_equals_character)
{
	EXPECT_FALSE(ms_int_validate_env_name("="));
}
