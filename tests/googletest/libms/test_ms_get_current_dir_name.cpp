#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <unistd.h>
};

// 最初に入っている環境変数と同じであること。
TEST(ms_get_current_dir_name, equal_lib)
{
	char	*origin;
	char	*self;

	self = ms_get_current_dir_name();
	ASSERT_NE(self, nullptr);
	origin = get_current_dir_name();
	ASSERT_NE(origin, nullptr);
	EXPECT_STREQ(self, origin);
	free(self);
	free(origin);
}
