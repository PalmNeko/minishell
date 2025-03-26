#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
	#include <sys/types.h>
};

typedef std::tuple<std::string, std::string, int> TestResult;
static auto getStdout = [](const TestResult &t) { return std::get<0>(t); };
static auto getStderr = [](const TestResult &t) { return std::get<1>(t); };
static auto getStatus = [](const TestResult &t) { return std::get<2>(t); };

/**
 * return stdout stderr status
 */
std::tuple<std::string, std::string, int> test_runner_of_builtin_env(char **args, char **envp)
{

	int status;
	std::string stdOut;
	std::string stdErr;
	std::tuple<std::string, std::string, int> t;

	// 環境変数の設定
	ms_clear_exports();
	while (envp != NULL && *envp != NULL)
	{
		char	*name;
		char	*nameend;
		char	*value;

		nameend = ft_strchr(*envp, '=');
		if (nameend != NULL)
		{
			name = ft_strndup(*envp, nameend - *envp);
			value = ft_strdup(nameend + 1);
			ms_setenv(name, value, 1);
			ms_add_export(name);
			free(name);
			free(value);
		}
		envp++;
	}

	// 実行
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	status = ms_builtin_env(NULL, args, NULL);
	stdOut = testing::internal::GetCapturedStdout();
	stdErr = testing::internal::GetCapturedStderr();
	t = std::make_tuple(stdOut, stdErr, status);
	return t;
}

std::string	generate_expect_env_output(const char **envp)
{
	std::string output;

	while (*envp != NULL)
	{
		output += *envp;
		output += "\n";
		envp++;
	}
	return output;
}

/** envコマンドと一致することを確認する */
TEST(ms_builtin_env, equal_env_command)
{
	TestResult 	expect;
	TestResult 	result;
	const char 	*args[] = {"env", NULL};
	const char	*envp[] = {
		"PATH=/usr/bin:/bin",
		"HOME=/home/user",
		"USER=user",
		NULL
	};
	std::string expect_stdout;

	expect_stdout = generate_expect_env_output(envp);
	expect = std::make_tuple(expect_stdout, "", 0);

	result = test_runner_of_builtin_env((char **)args, (char **)envp);
	EXPECT_EQ(getStdout(expect), getStdout(result));
	EXPECT_EQ(getStderr(expect), getStderr(result));
	EXPECT_EQ(getStatus(expect), getStatus(result));
}

/** envコマンドに無効なオプションが渡されたときはエラー */
TEST(ms_builtin_env, error_on_invalid_opt)
{
	TestResult 	expect;
	TestResult 	result;
	const char 	*args[] = {"env", "-a", NULL};
	char		**envp;

	expect = std::make_tuple(
		"",
		(
			"minishell: env: -a: invalid option\n"
			"env: usage: env\n"
		),
		2);
	envp = ms_export_env();
	ASSERT_NE(envp, nullptr);
	result = test_runner_of_builtin_env((char **)args, envp);
	ms_destroy_ntp(envp);

	EXPECT_EQ(getStdout(expect), getStdout(result));
	EXPECT_EQ(getStderr(expect), getStderr(result));
	EXPECT_EQ(getStatus(expect), getStatus(result));
}

/** 引数は無視する */
TEST(ms_builtin_env, ignore_argument)
{
	TestResult 	expect;
	TestResult 	result;
	const char 	*args[] = {"env", "--", "-a", NULL};
	char		**envp;

	expect = std::make_tuple("", "minishell: env: too many arguments\n", 1);
	envp = ms_export_env();
	ASSERT_NE(envp, nullptr);
	result = test_runner_of_builtin_env((char **)args, envp);
	ms_destroy_ntp(envp);

	EXPECT_EQ(getStdout(expect), getStdout(result));
	EXPECT_EQ(getStderr(expect), getStderr(result));
	EXPECT_EQ(getStatus(expect), getStatus(result));
}
