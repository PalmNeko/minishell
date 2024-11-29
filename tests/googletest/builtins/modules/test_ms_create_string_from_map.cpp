#include <gtest/gtest.h>

extern "C" {
	#include "libft.h"
    #include "builtin_internal.h"
	#include <stdlib.h>
};

// 設定されている文字を文字列として出力すること。asciiコードで昇順にソートされて出力される。
TEST(ms_create_string_from_map, basic)
{
	bool	map[256];
	char	*str;

	ft_memset(map, false, 256);
	map['a'] = true;
	map['2'] = true;
	map['A'] = true;
	str = ms_create_string_from_map(map);
	ASSERT_NE(str, nullptr);
	EXPECT_STREQ(str, "2Aa");
	free(str);
}
