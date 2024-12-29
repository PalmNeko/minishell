#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
	#include <stdlib.h>
};

// =で結合されていること。
TEST(ms_int_ms_var_to_string, basic)
{
	t_ms_var ms_var = {
		.name = (char *)"name",
		.value = (char *)"value"
	};
	char	*str;

	str = ms_int_ms_var_to_string(&ms_var);
	ASSERT_NE(str, nullptr);
	EXPECT_STREQ(str, "name=value");
	free(str);
}
