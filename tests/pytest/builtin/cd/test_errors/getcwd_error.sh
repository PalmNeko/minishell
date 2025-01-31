#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

# ディレクトリの作成
mkdir tmp

# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
pwd
cd tmp
rm -r ../tmp
cd .
pwd
echo $?
EOF

# 後始末
rm -r tmp
