#include <gtest/gtest.h>

extern "C" {
    #include "ms_getopt.h"
};

// optingを初期化する
TEST(ms_getopt_init, basic)
{
	t_opting	opting;
	const char	*args[] = {"./a.out", "-a", "b", NULL};

	ms_getopt_init(&opting, 3, (char **)args, "ab");
	EXPECT_EQ(opting.argc, 3);
	EXPECT_EQ(opting.argv[0], "./a.out");
	EXPECT_EQ(opting.argv[1], "-a");
	EXPECT_EQ(opting.argv[2], "b");
	EXPECT_EQ(opting.optstring, "ab");
	EXPECT_EQ(opting.is_skip_double_hyphen, true);
	EXPECT_EQ(opting.is_valid, false);
	EXPECT_EQ(opting.is_valid_optstatement, false);
	EXPECT_EQ(opting.optind, 1);
	EXPECT_EQ(opting.nowind, 1);
	EXPECT_EQ(opting.optopt, 0);
	EXPECT_EQ(opting.internal.is_parsed, false);
	EXPECT_EQ(opting.internal.optpos, 1);
}
