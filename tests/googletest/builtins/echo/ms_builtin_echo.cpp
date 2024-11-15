#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "builtin.h"
	#include "ms_test.h"
	#include <unistd.h>
	#include <fcntl.h>
	#include <stdlib.h>
};

static std::string	ms_get_output(const char *args[]);
static char	**ms_dup_ntp(const char *const ntp[]);
static void	ms_destroy_ntp(char *ntp[]);

/** 引数がないときは改行のみを出力する */
TEST(builtin_echo, single_newline_when_no_arg)
{
	std::string output;
	const char *args[] = {"echo", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "\n");
}

/** 引数が渡されたときは、引数と改行を出力する */
TEST(builtin_echo, must_print_argument_and_newline)
{
	std::string output;
	const char *args[] = {"echo", "abs", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "abs\n");
}

/** 複数の引数は空白で連結する（最後に空白はあってはいけない） */
TEST(builtin_echo, must_join_whitespace)
{
	std::string output;
	const char *args[] = {"echo", "sba", "abs", "kkk", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "sba abs kkk\n");
}

/** 引数に空白があっても勝手に削除しない */
TEST(builtin_echo, must_not_arbitrarily_trim)
{
	std::string output;
	const char *args[] = {"echo", "sba ", " abs  ", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "sba   abs  \n");
}

/** nオプションが渡されたうえで引数を渡されたときは改行しない */
TEST(builtin_echo, must_print_argument_no_line)
{
	std::string output;
	const char *args[] = {"echo", "-n", "abs", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "abs");
}

/** オプションが連続していても出力しない */
TEST(builtin_echo, must_not_print_hyphen)
{
	std::string output;
	const char *args[] = {"echo", "-n", "-n", "abs", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "abs");
}

/** オプション出ない文字が出た後はそのまま出力する */
TEST(builtin_echo, must_print_hyphen_and_n)
{
	std::string output;
	const char *args[] = {"echo", "-n", "sba", "-n", "abs", NULL};

	output = ms_get_output(args);
    EXPECT_EQ(output, "sba -n abs");
}


static std::string	ms_get_output(const char *args[])
{
	CaptureFd cap;
	std::string output;
	char **duped_args;
	char *envp[] = {NULL};

	duped_args = ms_dup_ntp(args);
	if (duped_args == NULL)
		return ("(null)");
	cap.capture(1);
	ms_builtin_echo("", duped_args, envp);
	output = cap.read();
	cap.unCapture();
	ms_destroy_ntp(duped_args);
	return (output);
}

static char	**ms_dup_ntp(const char *const ntp[])
{
	size_t	index;
	char	**duped_ntp;

	index = 0;
	while (ntp[index] != NULL)
		index++;
	duped_ntp = (char **)calloc((index + 1), sizeof(char *));
	if (duped_ntp == NULL)
		return (NULL);
	index = 0;
	while (ntp[index] != NULL)
	{
		duped_ntp[index] = strdup(ntp[index]);
		if (duped_ntp[index] == NULL)
			return (ms_destroy_ntp(duped_ntp), nullptr);
		index++;
	}
	duped_ntp[index] = NULL;
	return (duped_ntp);
}

static void	ms_destroy_ntp(char *ntp[])
{
	size_t	index;

	if (ntp == NULL)
		return ;
	index = 0;
	while (ntp[index] != NULL)
	{
		free(ntp[index]);
		index++;
	}
	free(ntp);
}
