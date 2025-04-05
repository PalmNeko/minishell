#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
TEMP=$SHLVL
SHLVL=
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF
SHLVL=$TEMP
