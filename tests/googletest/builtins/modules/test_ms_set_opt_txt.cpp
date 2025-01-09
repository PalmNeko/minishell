#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// オプション引数の形に変更すること。
TEST(ms_set_opt_txt, basic)
{
	char	opt[3];

	ms_set_opt_txt(opt, 'c');
	EXPECT_STREQ(opt, "-c");
}
