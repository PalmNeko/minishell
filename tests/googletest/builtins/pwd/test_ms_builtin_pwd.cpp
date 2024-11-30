#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include <unistd.h>
};

/** 引数がないときは改行のみを出力する */
TEST(ms_builtin_pwd, equal_current_directory)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"pwd", NULL};
	char		*cwd;

	cwd = get_current_dir_name();
	ASSERT_NE(cwd, nullptr);
	expect_status = 0;
	expectStdout =
		std::string(cwd) + "\n";
	expectStderr =
		"";
	free(cwd);

	term.boot();
	status = ms_builtin_pwd(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** 無効な引数が含まれる場合は、エラーを出力する。 */
TEST(ms_builtin_pwd, output_error_on_invalid_opt)
{
	IoTerminal  term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int 		status;
	const char 	*args[] = {"pwd", "-a", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"minishell: pwd: -a: invalid option\n"
		"pwd: usage: pwd\n";

	term.boot();
	status = ms_builtin_pwd(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** 通常の引数の後は無視して実行する。 */
TEST(ms_builtin_pwd, ignore_normal_arguments)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"pwd", "asfd", "-a", NULL};
	char		*cwd;

	cwd = get_current_dir_name();
	ASSERT_NE(cwd, nullptr);
	expect_status = 0;
	expectStdout =
		std::string(cwd) + "\n";
	expectStderr =
		"";
	free(cwd);

	term.boot();
	status = ms_builtin_pwd(NULL, (char *const *)args, NULL);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}
