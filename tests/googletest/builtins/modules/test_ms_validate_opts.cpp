#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// すべて有効なオプションであれば、TRUEを返す。
TEST(ms_validate_opts, true_if_all_valid_opts)
{
	EXPECT_TRUE(ms_validate_opts("-12", "123"));
	EXPECT_TRUE(ms_validate_opts("-nnnnn", "n"));
	EXPECT_TRUE(ms_validate_opts("-nnnnn-", "n-"));
}

// 無効なオプションがあれば、FALSEを返す。
TEST(ms_validate_opts, false_if_has_invalid_opts)
{
	EXPECT_FALSE(ms_validate_opts("--", "-"));
	EXPECT_FALSE(ms_validate_opts("--", "a"));
	EXPECT_FALSE(ms_validate_opts("-abn", "a"));
}
