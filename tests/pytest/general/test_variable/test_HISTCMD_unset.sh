#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
unset HISTCMD
HISTCMD=3
echo $HISTCMD
echo $HISTCMD
EOF
