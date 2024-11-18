#!/bin/bash

# コンパイルして標準出力に結果のファイルを出力

main() {
	cd "$(dirname $0)" || err_exit "Error: change directory $(dirname $0)"
	cd "../../src" || err_exit "Error: change directory ../../src"
	BIN_DIR="$(pwd)"
	make -s || err_exit "Error: make error"
	echo "$BIN_DIR/minishell"
}

err_exit() {
	echo "$1" > /dev/stderr
	exit 1
}

main
