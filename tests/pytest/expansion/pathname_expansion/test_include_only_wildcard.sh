#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
. "module/create_testdir.sh"
cd testdir
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
echo *
EOF
cd ../
rm -rf testdir