#!/bin/bash

#
# 一般的で普通の使い方をしたときのテスト
#

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../../test_prepare.sh"

# ディレクトリの作成
mkdir -p physical_dir
ln -s physical_dir symbolic_dir

# テスト
$LEAKCHECK $PROG << "EOF"
cd physical_dir
pwd
cd ..

cd symbolic_dir
pwd
cd ..
EOF

# ディレクトリの削除
rm -rf physical_dir symbolic_dir
