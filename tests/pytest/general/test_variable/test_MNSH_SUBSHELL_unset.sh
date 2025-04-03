#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
unset MNSH_SUBSHELL
echo $MNSH_SUBSHELL
MNSH_SUBSHELL=3
( echo $MNSH_SUBSHELL )
echo $?
EOF
