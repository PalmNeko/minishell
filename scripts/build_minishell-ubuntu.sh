#!/bin/bash

cd "$(dirname $0)" || exit 1
docker build ../docker/ubuntu -t ghcr.io/palmneko/minishell-ubuntu:22.04 --target test
