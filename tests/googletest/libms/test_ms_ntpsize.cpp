#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include "libft.h"
	#include <stdlib.h>
};

// 数える
TEST(ms_ntpsize, get_size)
{
	const char *ptr[] = {"123", "3321", NULL};
	size_t		size;

	size = ms_ntpsize((void **)ptr);
	EXPECT_EQ(size, 2);
}

// 数える
TEST(ms_ntpsize, only_null)
{
	const char *ptr[] = {NULL};
	size_t		size;

	size = ms_ntpsize((void **)ptr);
	EXPECT_EQ(size, 0);
}
