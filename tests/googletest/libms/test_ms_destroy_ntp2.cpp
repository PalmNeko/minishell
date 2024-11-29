#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
};

// メモリを開放してメモリリークしていないこと
TEST(ms_destroy_ntp2, basic)
{
	char **str;
	const char *ntp[] = {"Hello", "World", "!!!", NULL};

	str = ms_dup_ntp(ntp); // valgrindを呼び出して確認する。
	ms_destroy_ntp2((void **)str, free);
}
