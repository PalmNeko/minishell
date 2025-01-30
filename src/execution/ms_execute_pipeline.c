/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:51:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:45:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
** 単コマンド, 複数コマンド, 無コマンドの処理を行う
*/
static int	ms_single_command_execution(t_lsa_pipeline *pipeline);
static int	ms_multiple_command_execution(t_lsa_pipeline *pipeline);
static int	ms_execute_pipeline_fork(t_lsa_command *lsa_command,
				t_state_in_pipeline state, int pipe_fd[2]);

int	ms_execute_pipeline(t_lsa_pipeline *pipeline)
{
	int	ret;

	// パイプラインの種類（単コマンド、複数コマンド、無コマンド）によって処理を分岐
	if (pipeline->commands[0]->args == NULL)
		ret = ms_simple_command_execution(pipeline->commands[0]);
	else if (pipeline->commands[1] == NULL)
		ret = ms_single_command_execution(pipeline);
	else
		ret = ms_multiple_command_execution(pipeline);
	return (ret);
}

static int	ms_single_command_execution(t_lsa_pipeline *pipeline)
{
	int	ret;

	if (ms_isbuiltin((char *)pipeline->commands[0]->args[0]->word_list->children[0]->token->token))
		ret = ms_simple_command_execution(pipeline->commands[0]);
	else
		ret = ms_execute_pipeline_fork(pipeline->commands[0], SINGLE_COMMAND,
				NULL);
	return (ret);
}

static int	ms_multiple_command_execution(t_lsa_pipeline *pipeline)
{
	int	pipe_fd[2];
	int	i;
	int	ret;

	i = 0;
	if (pipe(pipe_fd) == -1 || pipe(pipe_fd) == -1)
		return (1);
	while (pipeline->commands[i])
	{
		if (i == 0)
			ret = ms_execute_pipeline_fork(pipeline->commands[i], FIRST_COMMAND,
					pipe_fd);
		else if (pipeline->commands[i + 1] == NULL)
			ret = ms_execute_pipeline_fork(pipeline->commands[i], LAST_COMMAND,
					pipe_fd);
		else
			ret = ms_execute_pipeline_fork(pipeline->commands[i],
					MIDDLE_COMMAND, pipe_fd);
		i++;
		if (ret != 0)
			break ;
	}
	return (ret);
}

// memo
// pipelineの最後に篇数代入が来ると篇数代入は行われる？
static int	ms_execute_pipeline_fork(t_lsa_command *lsa_command,
		t_state_in_pipeline state, int pipe_fd[2])
{
	int	ret;

	ret = 0;
	if (fork() == 0)
	{
		if ((state & FIRST_COMMAND) == 0)
		{
			if (close(STDIN_FILENO) == -1 || dup2(pipe_fd[0], STDIN_FILENO) ==
				-1 || close(pipe_fd[0]) == -1)
				return (1);
		}
		if ((state & LAST_COMMAND) == 0)
		{
			if (close(STDOUT_FILENO) || dup2(pipe_fd[1], STDOUT_FILENO)
				|| close(pipe_fd[1]))
				return (1);
		}
		ret = ms_simple_command_execution(lsa_command);
		return (ret);
	}
	else
		wait(NULL);
	return (ret);
}
