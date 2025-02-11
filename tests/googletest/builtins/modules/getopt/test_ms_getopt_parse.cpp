#include <gtest/gtest.h>

extern "C" {
    #include "ms_getopt.h"
};

// optingを初期化する
TEST(ms_getopt_parse, basic)
{
	t_opting	opting;
	const char	*args[] = {"./a.out", "-ba", "-bc", "--", "b", NULL};

	ms_getopt_init(&opting, 5, (char **)args, "ab");

	EXPECT_EQ(ms_getopt_parse(&opting), true); // 解析対象 -b
	EXPECT_EQ(opting.optopt, 'b');
	EXPECT_EQ(opting.is_valid, true);
	EXPECT_EQ(opting.is_valid_optstatement, true);
	EXPECT_EQ(opting.optind, 1);
	EXPECT_EQ(opting.nowind, 1);
	EXPECT_EQ(opting.internal.optpos, 2);
	EXPECT_EQ(opting.internal.is_parsed, false);

	EXPECT_EQ(ms_getopt_parse(&opting), true); // -a
	EXPECT_EQ(opting.optopt, 'a');
	EXPECT_EQ(opting.is_valid, true);
	EXPECT_EQ(opting.is_valid_optstatement, true);
	EXPECT_EQ(opting.optind, 2);
	EXPECT_EQ(opting.nowind, 1);
	EXPECT_EQ(opting.internal.optpos, 1);
	EXPECT_EQ(opting.internal.is_parsed, false);

	EXPECT_EQ(ms_getopt_parse(&opting), true); // -b
	EXPECT_EQ(opting.optopt, 'b');
	EXPECT_EQ(opting.is_valid, true);
	EXPECT_EQ(opting.is_valid_optstatement, false);
	EXPECT_EQ(opting.optind, 2);
	EXPECT_EQ(opting.nowind, 2);
	EXPECT_EQ(opting.internal.optpos, 2);
	EXPECT_EQ(opting.internal.is_parsed, false);

	EXPECT_EQ(ms_getopt_parse(&opting), true); // -c
	EXPECT_EQ(opting.optopt, 'c');
	EXPECT_EQ(opting.is_valid, false);
	EXPECT_EQ(opting.is_valid_optstatement, false);
	EXPECT_EQ(opting.optind, 3);
	EXPECT_EQ(opting.nowind, 2);
	EXPECT_EQ(opting.internal.optpos, 1);
	EXPECT_EQ(opting.internal.is_parsed, false);

	EXPECT_EQ(ms_getopt_parse(&opting), false); // --
	EXPECT_EQ(opting.optind, 4);
	EXPECT_EQ(opting.internal.is_parsed, true);

	EXPECT_EQ(ms_getopt_parse(&opting), false); // b
	EXPECT_EQ(opting.optind, 4);
	EXPECT_EQ(opting.internal.is_parsed, true);
}

TEST(ms_getopt_parse, no_hyphen_skip)
{
	t_opting	opting;
	const char	*args[] = {"./a.out", "-a", "--", "b", NULL};

	ms_getopt_init(&opting, 5, (char **)args, "ab");
	opting.is_skip_double_hyphen = false;
	EXPECT_EQ(ms_getopt_parse(&opting), true);
	EXPECT_EQ(ms_getopt_parse(&opting), false);
	EXPECT_STREQ(opting.argv[opting.optind], "--");
}
