#!/bin/bash

cd "$(dirname $0)" || exit 1
docker build . -t ghcr.io/palmneko/minishell-ubuntu:22.04