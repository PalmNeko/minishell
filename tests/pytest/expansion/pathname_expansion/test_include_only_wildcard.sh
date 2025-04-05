#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
. "module/create_testdir.sh"
cd testdir
$LEAKCHECK $PROG << "EOF"
echo * | tr ' ' '\n' | grep -vE "^$" | sort
EOF
cd ../
rm -rf testdir
