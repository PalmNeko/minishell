#include <gtest/gtest.h>

extern "C" {
    #include "builtin_internal.h"
};

// 文字の位置にtrueが設定されること。
TEST(ms_set_character_map, basic)
{
	bool	map[256];

	ms_set_character_map("2aA", map);
	EXPECT_TRUE(map['2']);
	EXPECT_TRUE(map['a']);
	EXPECT_TRUE(map['A']);
}
