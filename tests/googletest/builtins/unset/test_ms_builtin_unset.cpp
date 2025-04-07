#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
};

/** 引数がないときは、何もしない */
TEST(ms_builtin_unset, do_nothing)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"unset", NULL};

	expect_status = 0;
	expectStdout =
		"";
	expectStderr =
		"";

	term.boot();
	status = ms_builtin_unset(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** 引数に対してunsetを実行する。 */
TEST(ms_builtin_unset, can_unset)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"unset", "FOR_BUILTIN_USET", NULL};

	expect_status = 0;
	expectStdout =
		"";
	expectStderr =
		"";

	ms_setenv("FOR_BUILTIN_USET", "123", 0);
	EXPECT_STREQ(ms_getenv("FOR_BUILTIN_USET"), "123");
	term.boot();
	status = ms_builtin_unset(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
	EXPECT_EQ(ms_getenv("FOR_BUILTIN_USET"), nullptr);
}

/** 無効なオプション引数はエラーを返す。 */
TEST(ms_builtin_unset, error_if_use_invalid_option)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"unset", "-123", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"minishell: unset: -1: invalid option\n"
		"unset: usage: unset [name ...]\n";

	term.boot();
	status = ms_builtin_unset(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** exportの方もunsetする */
TEST(ms_builtin_unset, unset_export_environ)
{
	IoTerminal 	term;
	const char 	*args[] = {"unset", "HOGE", NULL};
	t_list		*export_env;

	ms_setenv("HOGE", "\\\"", 1);

	term.boot();
	ms_builtin_unset(NULL, (char *const *)args, NULL);
	term.exit();

	export_env = ms_find_export("HOGE");
	EXPECT_EQ(export_env, nullptr);
}
