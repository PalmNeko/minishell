#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"

. "../../test_prepare.sh"

# テスト
cd testdir
$LEAKCHECK $PROG << "EOF"
echo */*
EOF
cd ../
