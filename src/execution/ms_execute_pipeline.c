/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:51:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 17:41:13 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "syntax_analyze.h"
#include "libms.h"

static int	ms_single_command_execution(t_lsa_pipeline *pipeline);
static int	ms_multiple_command_execution(t_lsa_pipeline *pipeline);
static int	ms_execute_pipeline_fork(t_lsa_command *lsa_command,
				t_state_in_pipeline state, int *pipe_fd);
static int	ms_execute_pipeline_child(t_lsa_command *lsa_command,
				t_state_in_pipeline state, int *pipe_fd, int *new_pipe_fd);

int	ms_execute_pipeline(t_lsa_pipeline *pipeline)
{
	int	ret;

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
	int		ret;
	char	**expanded_strings;

	expanded_strings = ms_expansion(pipeline->commands[0]->args[0]);
	if (expanded_strings[0] && ms_isbuiltin(expanded_strings[0]) == 1)
	{
		ret = ms_simple_command_execution(pipeline->commands[0]);
	}
	else
		ret = ms_execute_pipeline_fork(pipeline->commands[0], SINGLE_COMMAND,
				NULL);
	ms_destroy_ntp2((void **)expanded_strings, free);
	return (ret);
}

static int	ms_multiple_command_execution(t_lsa_pipeline *pipeline)
{
	int			i;
	int			ret;
	static int	pipe_fd[2] = {-1, -1};

	i = 0;
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
	}
	return (ret);
}

// memo
// pipelineの最後に篇数代入が来ると篇数代入は行われる？
static int	ms_execute_pipeline_fork(t_lsa_command *lsa_command,
	t_state_in_pipeline state, int *pipe_fd)
{
	int		status;
	pid_t	pid;
	int		new_pipe_fd[2];

	if (!(state & LAST_COMMAND))
		if (pipe(new_pipe_fd) == -1)
			return (1);
	pid = fork();
	if (pid == 0)
	{
		status = ms_execute_pipeline_child(lsa_command, state, pipe_fd, new_pipe_fd);
		status = ms_add_meta(status, IS_CHILD);
		return (status);
	}
	else
	{
		if (!(state & FIRST_COMMAND))
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
		}
		if (!(state & LAST_COMMAND))
		{
			ft_memcpy(pipe_fd, new_pipe_fd, sizeof(int) * 2);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

//close_errorを考慮
static int	ms_execute_pipeline_child(t_lsa_command *lsa_command,
		t_state_in_pipeline state, int *pipe_fd, int *new_pipe_fd)
{
	int	ret;

	if ((state & FIRST_COMMAND) == 0)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			return (1);
		close(pipe_fd[0]);
	}
	if ((state & LAST_COMMAND) == 0)
	{
		close(new_pipe_fd[0]);
		if (dup2(new_pipe_fd[1], STDOUT_FILENO) == -1)
			return (1);
		close(new_pipe_fd[1]);
	}
	ret = ms_simple_command_execution(lsa_command);
	return (ret);
}
