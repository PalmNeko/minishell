#!/bin/bash

# テスト用の設定の読み込み
cd "$(dirname $0)"
. "../../test_prepare.sh"

# テスト
$LEAKCHECK $PROG << "EOF"
echo 1 && echo 2 || echo 3 && acho 4 || echo 5  
EOF