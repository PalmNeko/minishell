#!/bin/bash

# minishellのバイナリのあるパス
PROG="$(bash $(dirname "$BASH_SOURCE")/build_minishell.sh)" || exit 1
