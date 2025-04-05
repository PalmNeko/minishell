#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include <stdlib.h>
};

// 普通の文字はそのまま出力されること
TEST(ms_dup_escapedstr, basic)
{
	char	*escaped;

	escaped = ms_dup_escapedstr("hello");
	if (escaped == NULL)
		FAIL();
	EXPECT_STREQ(escaped, "hello");
	free(escaped);
}

// エスケープ文字はエスケープされて出力されること
TEST(ms_dup_escapedstr, will_escaped_character)
{
	char	*escaped;

	escaped = ms_dup_escapedstr("\a \b \e \f \n \r \t \v \\ '");
	if (escaped == NULL)
		FAIL();
	EXPECT_STREQ(escaped, "\\a \\b \\E \\f \\n \\r \\t \\v \\\\ \\'");
	free(escaped);
}

// 出力できない数値は８進数で出力されること
TEST(ms_dup_escapedstr, will_escape_with_octal)
{
	char	*escaped;

	escaped = ms_dup_escapedstr("\01 \020 \x7f \x8f \xff");
	if (escaped == NULL)
		FAIL();
	EXPECT_STREQ(escaped, "\\001 \\020 \\177 \\217 \\377");
	free(escaped);
}
