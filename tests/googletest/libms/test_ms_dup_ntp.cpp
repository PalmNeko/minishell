#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
};

// 間違いなくコピーできること
TEST(ms_dup_ntp, basic)
{
	char **str;
	const char *ntp[] = {"Hello", "World", "!!!", NULL};

	str = ms_dup_ntp(ntp);
	EXPECT_STREQ(str[0], "Hello");
	EXPECT_STREQ(str[1], "World");
	EXPECT_STREQ(str[2], "!!!");
	EXPECT_EQ(str[3], nullptr);
	ms_destroy_ntp(str);
}

// NULLしかなくてもコピーできること
TEST(ms_dup_ntp, only_null)
{
	char **str;
	const char *ntp[] = {NULL};

	str = ms_dup_ntp(ntp);
	EXPECT_EQ(str[0], nullptr);
	ms_destroy_ntp(str);
}
