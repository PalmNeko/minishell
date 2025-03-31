#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
echo < $A$A
echo $?
echo > $Bob
echo $?
echo >> $Chris
echo $?
EOF

rm -f tmp.test
