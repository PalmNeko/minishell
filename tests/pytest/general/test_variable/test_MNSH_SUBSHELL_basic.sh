#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
MNSH_SUBSHELL=0
( ( echo $MNSH_SUBSHELL && MNSH_SUBSHELL=4 && ( echo $MNSH_SUBSHELL ) ) )
echo $?
EOF
