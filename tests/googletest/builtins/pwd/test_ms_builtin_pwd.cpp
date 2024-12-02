#include "IoTerminal.hpp"
#include "IoCapture.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include <unistd.h>
};

IoCapture	*testBuiltinPwd(const char *path, char *const *argv, char *const *envp)
{
	IoCapture *term = new IoCapture;

	term->boot();
	if (term->isCapturing()) {
		int status;
		status = ms_builtin_pwd(path, (char *const *)argv, envp);
		exit(status);
	}
	term->exit();
	return (term);
}

/** 引数がないときは改行のみを出力する */
TEST(ms_builtin_pwd, equal_current_directory)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
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

	IoCapture *term;
	term = testBuiltinPwd(NULL, (char *const *)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 無効な引数が含まれる場合は、エラーを出力する。 */
TEST(ms_builtin_pwd, output_error_on_invalid_opt)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"pwd", "-a", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"minishell: pwd: -a: invalid option\n"
		"pwd: usage: pwd\n";

	IoCapture *term;
	term = testBuiltinPwd(NULL, (char *const *)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 通常の引数の後は無視して実行する。 */
TEST(ms_builtin_pwd, ignore_normal_arguments)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
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

	IoCapture *term;
	term = testBuiltinPwd(NULL, (char *const *)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}
