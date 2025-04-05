#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

# ディレクトリの作成
mkdir -p tmp

# テスト
# PROG="bash"
export HOGE1=$'\a \b \e \f \n \r \t \v \\ \'' HOGE2=$'\001 \020 \x7f \x8f \xff'
$LEAKCHECK $PROG << "EOF"
cd "$HOGE1"
cd "$HOGE2"
EOF

# 後始末
rm -rf tmp
