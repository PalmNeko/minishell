#!/bin/bash

# minishellのバイナリのあるパス

PROG="$(cd $(dirname "$BASH_SOURCE")/../../src ; pwd)/minishell" || exit 1
if ! test -f "$PROG"; then
	echo "no such file: $PROG" > /dev/stderr
	exit 1
fi
