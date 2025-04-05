#include "IoCapture.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
	#include <sys/types.h>
};


IoCapture *testBuiltinExport(const char *path, char *const *argv, char *const *envp)
{
	IoCapture *term = new IoCapture;
	int status;

	term->boot();
	if (term->isCapturing())
	{
		status = ms_builtin_export(path, (char *const *)argv, envp);
		exit(status);
	}
	term->exit();
	return term;
}

/** 出力のテスト */
TEST(ms_builtin_export, basic)
{
	std::string expectStderr;
	std::string expectStdout;
	const char 	*args[] = {"export", NULL};

	expectStdout =
		"declare -x Alice=\"10\"\n"
		"declare -x Bob\n"
		"declare -x Chair\n"
		"declare -x Charlie\n";
	expectStderr =
		"";

	// 設定
	ms_clear_environ(NULL);
	ms_clear_exports();
	ms_setenv("Alice", "10", 1);
	ms_setenv("Chocolate", "", 1);
	ms_add_export("Bob");
	ms_add_export("Bob");
	ms_add_export("Charlie");
	ms_add_export("Chair");
	ms_add_export("Alice");

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 変数設定のテスト */
TEST(ms_builtin_export, can_set_environ)
{
	const char 	*args[] = {"export", "A==123", "B=321=", "C=", "D", NULL};
	const char 	*args2[] = {"export", "A+==123", "B+=", NULL};

	// 設定
	ms_clear_environ(NULL);
	ms_setenv("A", "333", 1);

	// 実行
	ms_builtin_export(NULL, (char *const *)args, NULL);

	// テスト
	EXPECT_STREQ(ms_getenv("A"), "=123");
	EXPECT_STREQ(ms_getenv("B"), "321=");
	EXPECT_STREQ(ms_getenv("C"), "");
	EXPECT_EQ(ms_getenv("D"), nullptr);

	// 実行
	ms_builtin_export(NULL, (char *const *)args2, NULL);

	// テスト
	EXPECT_STREQ(ms_getenv("A"), "=123=123");
	EXPECT_STREQ(ms_getenv("B"), "321=");
}

/** エラーのテスト */
TEST(ms_builtin_export, invalid_optin)
{
	std::string expectStderr;
	std::string expectStdout;
	const char 	*args[] = {"export", "-a", NULL};

	expectStdout =
		"";
	expectStderr =
		"minishell: export: -a: invalid option\n"
		"export: usage: export [name[=value] ...]\n";

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

TEST(ms_builtin_export, name_length_zero_error)
{
	std::string expectStderr;
	std::string expectStdout;
	int	expectStatus;
	const char 	*args[] = {"export", "=321", "=", "", "+=", NULL};

	expectStdout =
		"";
	expectStderr =
		"minishell: export: `=321': not a valid identifier\n"
		"minishell: export: `=': not a valid identifier\n"
		"minishell: export: `': not a valid identifier\n"
		"minishell: export: `+=': not a valid identifier\n"
		;
	expectStatus = 1;

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
    EXPECT_EQ(term->getStatus(), expectStatus);
	delete term;
}

TEST(ms_builtin_export, invalid_sign_error)
{
	std::string expectStderr;
	std::string expectStdout;
	int	expectStatus;
	const char 	*args[] = {"export", "$=321", "!=", "#", "~+=", NULL};

	expectStdout =
		"";
	expectStderr =
		"minishell: export: `$=321': not a valid identifier\n"
		"minishell: export: `!=': not a valid identifier\n"
		"minishell: export: `#': not a valid identifier\n"
		"minishell: export: `~+=': not a valid identifier\n"
		;
	expectStatus = 1;

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
    EXPECT_EQ(term->getStatus(), expectStatus);
	delete term;
}

// 名前の最初に数字が来る場合　エラー
TEST(ms_builtin_export, first_number_error)
{
	std::string expectStderr;
	std::string expectStdout;
	int	expectStatus;
	const char 	*args[] = {"export", "1asd", "3dfwe=", "123", "89+=a", NULL};

	expectStdout =
		"";
	expectStderr =
		"minishell: export: `1asd': not a valid identifier\n"
		"minishell: export: `3dfwe=': not a valid identifier\n"
		"minishell: export: `123': not a valid identifier\n"
		"minishell: export: `89+=a': not a valid identifier\n"
		;
	expectStatus = 1;

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
    EXPECT_EQ(term->getStatus(), expectStatus);
	delete term;
}

// エスケープする
TEST(ms_builtin_export, escaped_char)
{
	std::string expectStderr;
	std::string expectStdout;
	int	expectStatus;
	const char 	*args[] = {"export", NULL};

	expectStdout = "declare -x HOGE=\"\\\\\\\"\"\n";
	expectStderr = "";
	expectStatus = 0;

	// 設定
	ms_clear_environ(NULL);
	ms_clear_exports();
	ms_setenv("HOGE", "\\\"", 1);
	ms_add_export("HOGE");

	// テスト
	IoCapture 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
    EXPECT_EQ(term->getStatus(), expectStatus);
	delete term;
}
