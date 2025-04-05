#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テストの実行
$LEAKCHECK $PROG << "EOF"
echo nothing_wildcard
EOF
rm -rf testdir
