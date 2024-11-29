#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin_internal.h"
};

// 有効なオプションを削除する。
TEST(ms_get_invalid_opts, remove_valid_opts)
{
	char	*invalid_opts;

	invalid_opts = ms_get_invalid_opts("asdb", "ab");
	ASSERT_NE(invalid_opts, nullptr);
	EXPECT_STREQ(invalid_opts, "sd");
}
