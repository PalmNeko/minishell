#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
TEMP=$SHLVL
SHLVL=
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF
SHLVL=$TEMP