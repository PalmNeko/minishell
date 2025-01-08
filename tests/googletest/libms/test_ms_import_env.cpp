#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <errno.h>
};

// 環境変数が正しく設定されていること。
TEST(ms_import_env, basic)
{
	const char	*manual_envp[] = {
		"Hello=Konnitiha",
		"World=Sekai",
		NULL
	};
	char		**dupped_envp;
	int			result;
	char		*value;

	dupped_envp = ms_dup_ntp(manual_envp);
	ASSERT_NE(dupped_envp, nullptr);
	result = ms_import_env(dupped_envp);
	ms_destroy_ntp(dupped_envp);
	ASSERT_EQ(result, 0);
	value = ms_getenv("Hello");
	EXPECT_STREQ(value, "Konnitiha");
	value = ms_getenv("World");
	EXPECT_STREQ(value, "Sekai");
}

// =が含まれていない場合はエラーを出力して、errnoを設定
TEST(ms_import_env, error_if_no_equals)
{
	const char	*manual_envp[] = {
		"Hello=Konnitiha",
		"Sekai",
		NULL
	};
	char		**dupped_envp;
	int			result;

	dupped_envp = ms_dup_ntp(manual_envp);
	ASSERT_NE(dupped_envp, nullptr);
	result = ms_import_env(dupped_envp);
	ms_destroy_ntp(dupped_envp);
	ASSERT_EQ(result, -1);
	EXPECT_EQ(errno, EINVAL);
}

// 変数名の長さが0の場合はエラーを出力して、errnoを設定
TEST(ms_import_env, error_if_name_length_is_zero)
{
	const char	*manual_envp[] = {
		"Hello=Konnitiha",
		"=Sekai",
		NULL
	};
	char		**dupped_envp;
	int			result;

	dupped_envp = ms_dup_ntp(manual_envp);
	ASSERT_NE(dupped_envp, nullptr);
	result = ms_import_env(dupped_envp);
	ms_destroy_ntp(dupped_envp);
	ASSERT_EQ(result, -1);
	EXPECT_EQ(errno, EINVAL);
}
