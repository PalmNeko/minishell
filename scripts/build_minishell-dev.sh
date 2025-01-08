#!/bin/bash

cd "$(dirname $0)" || exit 1
docker build ../docker/ubuntu -t ghcr.io/palmneko/minishell-dev:22.04 --target debug
