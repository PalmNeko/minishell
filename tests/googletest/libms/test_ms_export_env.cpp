#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <string.h>
};

// 最初に入っている環境変数と同じであること。
TEST(ms_export_env, equal_environ)
{
	char		**exported;
	char		**stored;
	char		**ptr_exp;
	char		**ptr_env;
	int			result;
	extern char	**environ;

	stored = ms_dup_ntp3(environ);
	ASSERT_NE(stored, nullptr);
	result = ms_import_env(stored);
	ms_destroy_ntp(stored);
	if (result == -1) {
		ASSERT_TRUE(false);
	}
	exported = ms_export_env();
	if (exported == nullptr)
		ms_destroy_ntp(stored);
	ASSERT_NE(exported, nullptr);
	ptr_env = environ;
	while (*ptr_env != NULL)
	{
		ptr_exp = exported;
		while (*ptr_exp != NULL)
		{
			EXPECT_EQ(*ptr_env, *ptr_exp);
			ptr_exp++;
		}
		ptr_env++;
	}
	ms_destroy_ntp(exported);
}
