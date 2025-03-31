#!/bin/bash

#
# current directory (./) Case
#

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

cd ../../../
# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
cd .
echo $PWD
cd ./
echo $PWD
EOF