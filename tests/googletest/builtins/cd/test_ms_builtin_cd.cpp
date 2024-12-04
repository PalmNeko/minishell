#include "IoTerminal.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
	#include "builtin.h"
	#include "libms.h"
	#include "ms_test.h"
	#include <unistd.h>
	#include <fcntl.h>
	#include <stdlib.h>
};

/** cdコマンドのテストはC言語でやるには複雑すぎるのでpytestで行う。 */
TEST(ms_builtin_cd, test_lists)
{
	// 以下のテストを行う
		// CDPATHを使用するテスト（ディレクトリのみを対象として検索する）
		// PWDを確認するテスト
		// ホームディレクトリに移動するテスト
		// OLDPATHに移動するテスト
		// -Lオプションのテスト
		// -Pオプションのテスト
		// -eオプションとの組み合わせテスト
		// -eオプションだけの場合のテスト
		// -Lと-Pを両方指定した場合のテスト 最後に指定したオプションが使用される。
}
