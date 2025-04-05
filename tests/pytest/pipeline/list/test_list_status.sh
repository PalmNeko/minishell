#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
not_such_command
echo -n && echo $?
ahog -n || echo $?
EOF
