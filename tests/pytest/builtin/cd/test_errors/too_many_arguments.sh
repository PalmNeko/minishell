#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
cd a b
echo $?
EOF
exit 0
