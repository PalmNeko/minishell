#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
umask 000
$LEAKCHECK $PROG << "EOF"
> tmp.test
ls -l tmp.test | awk '{print $1}'
EOF

rm -f tmp.test
