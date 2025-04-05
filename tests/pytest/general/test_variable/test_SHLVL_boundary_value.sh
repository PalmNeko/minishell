#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
export SHLVL=2147483646
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF

export SHLVL=2147483647
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF
