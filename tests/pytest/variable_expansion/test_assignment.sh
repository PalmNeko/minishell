#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../test_prepare.sh"

# テスト
LEAKCHECK="valgrind -q --error-exitcode=12 --leak-check=full"
$LEAKCHECK $PROG << "EOF"
HOGE=simple_value
echo $HOGE
HOGE="value  include   space"
echo $HOGE
HOGE="join double quoted & "non_quoted' & single quoted'
echo $HOGE
HOGE=hoge
HOGE=$HOGE$HOGE$HOGE
echo 'assignment($HOGE=hoge) self three time. '$HOGE
EOF
