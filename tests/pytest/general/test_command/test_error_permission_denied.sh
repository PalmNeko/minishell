#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
touch anyfile.out
chmod u-x anyfile.out
$LEAKCHECK $PROG << "EOF"
./anyfile.out
echo $?
EOF
rm anyfile.out
