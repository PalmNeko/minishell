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
	bool		has_flag;
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
		has_flag = false;
		ptr_exp = exported;
		while (*ptr_exp != NULL && has_flag == false)
		{
			if (strcmp(*ptr_env, *ptr_exp) == 0)
				has_flag = true;
			ptr_exp++;
		}
		if (has_flag == false)
			EXPECT_STREQ(*ptr_env, "not in exported");
		else
			EXPECT_TRUE(true);
		ptr_env++;
	}
	ms_destroy_ntp(exported);
}
