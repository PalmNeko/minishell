#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <errno.h>
	#include <string.h>
	#include <stdlib.h>
};

// 環境変数の取得が正しく動くこと。文字列として等しいこと。
TEST(ms_getenv, basic)
{
	char		**envs;
	char		*equal_ptr;
	char		*cutted_name;
	char		*value_ptr;

	envs = ms_export_env();
	ASSERT_NE(envs, nullptr);
	ASSERT_NE(envs[0], nullptr);
	equal_ptr = strchr(envs[0], '=');
	ASSERT_NE(equal_ptr, nullptr);
	cutted_name = strndup(envs[0], equal_ptr - envs[0]);
	ms_destroy_ntp(envs);
	value_ptr = ms_getenv(cutted_name);
	free(cutted_name);
	EXPECT_STREQ(equal_ptr + 1, value_ptr);
}

// 存在しない名前を参照したらnullptrを返す。
TEST(ms_getenv, no_exists_name)
{
	char	*value_ptr;

	value_ptr = ms_getenv("korehakittoso xnzaisinai");
	EXPECT_EQ(value_ptr, nullptr);
	value_ptr = ms_getenv("");
	EXPECT_EQ(value_ptr, nullptr);
}
