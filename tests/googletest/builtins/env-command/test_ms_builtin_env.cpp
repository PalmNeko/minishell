#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
	#include <sys/types.h>
};

/** envコマンドと一致することを確認する */
TEST(ms_builtin_env, equal_env_command)
{
	IoTerminal 	term;
	IoTerminal	envTerm;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"env", NULL};
	char		**envp;
	char		**envp_itr;

	envp = ms_export_env();
	envTerm.boot();
	envp_itr = envp;
	while (*envp_itr != NULL)
		printf("%s\n", *(envp_itr++));
	fflush(stdout);
	envTerm.exit();

	expect_status = 0;
	expectStdout = envTerm.getStdout();
	expectStderr = envTerm.getStderr();

	term.boot();
	status = ms_builtin_env(NULL, (char *const *)args, envp);
	fflush(stdout);
	term.exit();
	ms_destroy_ntp(envp);
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** envコマンドに無効なオプションが渡されたときはエラー */
TEST(ms_builtin_env, error_on_invalid_opt)
{
	IoTerminal 	term;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"env", "-a", NULL};
	char		**envp;

	envp = ms_export_env();
	ASSERT_NE(envp, nullptr);
	expect_status = 2;
	expectStdout =
		"";
	expectStderr =
		"minishell: env: -a: invalid option\n"
		"env: usage: env\n";

	term.boot();
	status = ms_builtin_env(NULL, (char *const *)args, envp);
	fflush(stdout);
	term.exit();
	ms_destroy_ntp(envp);
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}

/** 引数は無視する */
TEST(ms_builtin_env, ignore_argument)
{
	IoTerminal 	term;
	IoTerminal	envTerm;
	std::string expectStderr;
	std::string expectStdout;
	int			expect_status;
	int			status;
	const char 	*args[] = {"env", "--", "-a", NULL};

	expect_status = 1;
	expectStdout = "";
	expectStderr = "minishell: env: too many arguments\n";

	term.boot();
	status = ms_builtin_env(NULL, (char *const *)args, NULL);
	fflush(stdout);
	term.exit();
	EXPECT_EQ(status, expect_status);
    EXPECT_EQ(term.getStdout(), expectStdout);
    EXPECT_EQ(term.getStderr(), expectStderr);
}
