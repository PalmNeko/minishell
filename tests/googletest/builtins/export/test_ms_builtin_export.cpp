#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "libms.h"
	#include <unistd.h>
	#include <sys/types.h>
};

IoTerminal *testBuiltinExport(const char *path, char *const *argv, char *const *envp)
{
	IoTerminal *term = new IoTerminal;

	term->boot();
	ms_builtin_export(path, (char *const *)argv, envp);
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
	ms_setenv("Alice", "10", 1);
	ms_setenv("Chocolate", "", 1);
	ms_add_export("Bob");
	ms_add_export("Bob");
	ms_add_export("Charlie");
	ms_add_export("Chair");
	ms_add_export("Alice");

	// テスト
	IoTerminal 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}

/** 変数設定のテスト */
TEST(ms_builtin_export, can_set_environ)
{
	const char 	*args[] = {"export", "A==123", "B=321=", "C=", "D", NULL};


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
	IoTerminal 	*term;
	term = testBuiltinExport(NULL, (char *const*)args, NULL);
    EXPECT_EQ(term->getStdout(), expectStdout);
    EXPECT_EQ(term->getStderr(), expectStderr);
	delete term;
}
