#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "libms.h"
	#include <unistd.h>
	#include <fcntl.h>
	#include <stdlib.h>
};

// 空白区切り3つの文字列
TEST(ms_join_ntp, basic)
{
	char *str;
	const char *ntp[] = {"Hello", "World", "!!!", NULL};

	str = ms_join_ntp(ntp, " ");
	EXPECT_STREQ(str, "Hello World !!!");
	free(str);
}

// 対象の文字列が一つもないときは、空文字列
TEST(ms_join_ntp, no_string)
{
	char *str;
	const char *ntp[] = {NULL};

	str = ms_join_ntp(ntp, " ");
	EXPECT_STREQ(str, "");
	free(str);
}

// 空文字列で結合できること
TEST(ms_join_ntp, sep_length_zero)
{
	char *str;
	const char *ntp[] = {"Hello", "World", "!!!", NULL};

	str = ms_join_ntp(ntp, "");
	EXPECT_STREQ(str, "HelloWorld!!!");
	free(str);
}
