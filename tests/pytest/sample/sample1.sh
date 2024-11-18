#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../test_prepare.sh"

echo 'sample test stdout'
echo 'sample test stderr' > /dev/stderr

# # インタラクティブなシェルのテスト
# LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
# script -q -c "$LEAKCHECK $PROG" << EOF # ヒアドクでコマンドを入力
# oiwjefoijs
# EOF
# echo $?

# # インタラクティブでない場合のシェルのテスト
# echo 'echo test' | $PROG
