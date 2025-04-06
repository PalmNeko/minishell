#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"

# テスト
. "module/create_testdir.sh"
cd testdir
$LEAKCHECK $PROG << "EOF"
echo */*
EOF
cd ../
