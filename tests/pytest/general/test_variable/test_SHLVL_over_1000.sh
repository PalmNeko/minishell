#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
SHLVL=999 # SHLVL + 1 が 1000 以上になるとエラーが表示される。
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF

SHLVL=998 # エラーは表示されない
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF
