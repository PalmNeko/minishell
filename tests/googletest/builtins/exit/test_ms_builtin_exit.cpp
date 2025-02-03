#include "IoCapture.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
	#include <sys/types.h>
};

IoCapture *testBuiltinExit(const char *path, char *const *argv, char *const *envp)
{
	IoCapture *term = new IoCapture;

	term->boot();
	if (term->isCapturing())
	{
		ms_builtin_exit(path, (char *const *)argv, envp);
		exit(128);
	}
	term->exit();
	return term;
}

/** 終了処理が成功すること。 */
TEST(ms_builtin_exit, success)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", NULL};

	expect_status = 0;
	expectStdout =
		"";
	expectStderr =
		"exit\n";

	ms_setenv("?", "0", 1);

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 終了処理が成功すること。終了ステータス込み */
TEST(ms_builtin_exit, success_with_argument)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", "-1", NULL};

	expect_status = 255;
	expectStdout =
		"";
	expectStderr =
		"exit\n";

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 数字で解析不可能な場合はエラーを出力すること。 */
TEST(ms_builtin_exit, error_non_numeric_argument)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", "12a3", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"exit\n"
		"minishell: exit: 12a3: numeric argument required\n";

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** longの範囲を超える時エラーを出力すること */
TEST(ms_builtin_exit, error_erange)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", "00009223372036854775808", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"exit\n"
		"minishell: exit: 00009223372036854775808: numeric argument required\n";

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 2個以上の引数が渡されたときはエラーを出すこと。 */
TEST(ms_builtin_exit, error_many_argument)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", "00009223372036854775808", "123", NULL};

	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"exit\n"
		"minishell: exit: 00009223372036854775808: numeric argument required\n";

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** -- の後が、終了ステータスになるように処理すること。 */
TEST(ms_builtin_exit, skip_double_hyphen)
{
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	const char 	*args[] = {"exit", "--", "123", NULL};

	expect_status = 123;
	expectStdout =
		"";
	expectStderr =
		"exit\n";

	IoCapture 	*term;
	term = testBuiltinExit(NULL, (char *const*)args, NULL);
	EXPECT_EQ(term->getStatus(), expect_status);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}
