#include <gtest/gtest.h>

extern "C" {
    #include "libms_internal.h"
	#include <stdlib.h>
};

// まだ一度も環境変数を読み込んでいない場合、environ変数で初期化する。
TEST(ms_int_import_on_initial, basic)
{
	// テストを思いつかなかった。
}
