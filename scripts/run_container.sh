#!/bin/bash

cd "$(dirname $0)"
cd ..

if ! docker container ls | grep minishell; then
	if [ -z "$SSH_AUTH_SOCK" ]; then
		# Check for a currently running instance of the agent
		echo 'run ssh-agent'
		RUNNING_AGENT="`ps -ax | grep 'ssh-agent -s' | grep -v grep | wc -l | tr -d '[:space:]'`"
		if [ "$RUNNING_AGENT" = "0" ]; then
			# Launch a new instance of the agent
			echo 'run ssh-agent'
			ssh-agent -s &> "$HOME"/.ssh/ssh-agent
		fi
		eval `cat "$HOME"/.ssh/ssh-agent` > /dev/null
		ssh-add "$HOME"/.ssh/* 2> /dev/null
	fi
	bash scripts/build_minishell-ubuntu.sh
	docker run \
		--rm \
		--init \
		--mount type=bind,source="$(pwd)",target=/app \
		--mount type=bind,source="$SSH_AUTH_SOCK",target="$SSH_AUTH_SOCK" \
		-e "SSH_AUTH_SOCK=$SSH_AUTH_SOCK" \
		--name minishell \
		-w /app \
		-u 0 \
		-it \
		-d \
		ghcr.io/palmneko/minishell-ubuntu:22.04 cat
	docker exec minishell git config --global user.email "$(git config user.email)"
	docker exec minishell git config --global user.name "$(git config user.name)"
fi

docker container exec -it minishell bash
