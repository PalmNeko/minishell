#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <string>

extern "C" {
    #include "execution.h"
	#include "libms.h"
	#include "lexical_analyze.h"
	#include "syntax_analyze.h"
	#include "semantic_analyze.h"
};

typedef std::tuple<std::string, std::string, int> TestResult;
static auto getStdout = [](const TestResult &t) { return std::get<0>(t); };
static auto getStderr = [](const TestResult &t) { return std::get<1>(t); };
static auto getStatus = [](const TestResult &t) { return std::get<2>(t); };

/**
 * return stdout stderr status
 */
TestResult test_runner_of_ms_input(const char *input)
{
	int status;
	std::string stdOut;
	std::string stdErr;
	TestResult t;

	// 実行
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	status = ms_execution(input);
	if (ms_has_meta(status, IS_CHILD))
	{
		status = ms_get_status_from_meta(status);
		exit(status);
	}
	stdOut = testing::internal::GetCapturedStdout();
	stdErr = testing::internal::GetCapturedStderr();
	t = std::make_tuple(stdOut, stdErr, status);
	return t;
}

TEST(Execute, ms_execution)
{
	std::string input = "echo $HOME";
	std::string expected_output = getenv("HOME") + std::string("\n");

	testing::internal::CaptureStdout();
	int ret = ms_execution(input.c_str());
	ASSERT_EQ(ret, 0);
	ASSERT_STREQ(testing::internal::GetCapturedStdout().c_str(), expected_output.c_str());
}

TEST(Execute, ms_execution_redirect_error_when_file_missing)
{
	TestResult expect("", "minishell: no_such_file: No such file or directory\n", 1);
	TestResult result = test_runner_of_ms_input("< no_such_file");

	ASSERT_EQ(getStdout(expect), getStdout(result));
	ASSERT_EQ(getStderr(expect), getStderr(result));
	ASSERT_EQ(getStatus(expect), getStatus(result));
}

TEST(Execute, ms_execution_redirect_error_when_file_missing_exist_external_command)
{
	TestResult expect("", "minishell: no_such_file: No such file or directory\n", 1);
	TestResult result = test_runner_of_ms_input("cat < no_such_file");

	ASSERT_EQ(getStdout(expect), getStdout(result));
	ASSERT_EQ(getStderr(expect), getStderr(result));
	ASSERT_EQ(getStatus(expect), getStatus(result));
}

TEST(Execute, ms_execution_redirect_error_when_file_missing_exist_builtin_command)
{
	TestResult expect("", "minishell: no_such_file: No such file or directory\n", 1);
	TestResult result = test_runner_of_ms_input("echo < no_such_file");

	ASSERT_EQ(getStdout(expect), getStdout(result));
	ASSERT_EQ(getStderr(expect), getStderr(result));
	ASSERT_EQ(getStatus(expect), getStatus(result));
}
