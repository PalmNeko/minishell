#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト -
# INT_MAX = 2147483647, INT_MIN = -2147483648
# INT_MAX*2 = 4294967294
# SHLVL = INT_MAX は 0 (INT_MINとして判断される)
# SHLVL = INT_MAX*2  は 0 (-2 として判断される)
# SHLVL = INT_MAX*2 + 1 は 0 (-1として判断される)
# SHLVL = INT_MAX*2 + 2 は 1 (0として判断される)
# ここでは、INT_MAX*2 + 2 + 2　が　3 として解釈されるものとして計算する
SHLVL=4294967298 # INT_MAX*2 + 2 + 2
$LEAKCHECK $PROG << "EOF"
echo $SHLVL
EOF
