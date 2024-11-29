#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin_internal.h"
};

// いずれかのオプションがあれば、trueを返す。
TEST(ms_get_invalid_opts, true_if_has_any_opts)
{
	EXPECT_TRUE(ms_has_opts("asdb", "zzza"));
}

// オプションがなければ、falseを返す。
TEST(ms_get_invalid_opts, false_if_has_no_any_opts)
{
	EXPECT_FALSE(ms_has_opts("asdb", "zolp"));
}
