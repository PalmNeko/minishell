#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
export -a
echo $?
EOF
