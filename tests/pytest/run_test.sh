#!/bin/bash

cd "$(dirname $0)" || exit 1

bash ./build_minishell.sh

pytest $@ .
