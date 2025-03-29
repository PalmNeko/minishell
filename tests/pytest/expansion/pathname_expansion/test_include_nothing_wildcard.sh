#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テストの実行
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
echo nothing_wildcard
EOF
rm -rf testdir