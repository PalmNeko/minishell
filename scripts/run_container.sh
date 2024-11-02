#!/bin/bash

cd "$(dirname $0)"
cd ..
bash scripts/build_minishell-ubuntu.sh
docker run \
	--rm \
	--mount type=bind,source="$(pwd)",target=/app \
	--name minishell \
	-w /app \
	-u 0 \
	-it \
	ghcr.io/palmneko/minishell-ubuntu:22.04 bash
