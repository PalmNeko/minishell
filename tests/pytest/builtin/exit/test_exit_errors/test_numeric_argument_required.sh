#!/bin/bash

#
# current directory (./) Case
#

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

cd ../../../
# テスト
$LEAKCHECK $PROG << "EOF"
exit a b
EOF
echo $?
