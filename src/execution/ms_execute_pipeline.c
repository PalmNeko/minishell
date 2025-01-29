/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:51:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 20:57:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <stdlib.h>
#include <sys/wait.h>

static int	ms_single_command_execution(t_lsa_pipeline *pipeline);
static int	ms_multiple_command_execution(t_lsa_pipeline *pipeline);
static int	ms_execute_pipeline_fork(t_lsa_command *lsa_command,
				t_state_in_pipeline state, int *pipe_fd);
static void	ms_execute_pipeline_child(t_lsa_command *lsa_command,
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
	int	ret;

	if (ms_isbuiltin((char *)pipeline->commands[0]->args[0]->word_list->children[0]))
		ret = ms_simple_command_execution(pipeline->commands[0]);
	else
		ret = ms_execute_pipeline_fork(pipeline->commands[0], SINGLE_COMMAND,
				NULL);
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
	int		ret;
	pid_t	pid;
	int		new_pipe_fd[2];

	ret = 0;
	if (!(state & LAST_COMMAND))
		if (pipe(new_pipe_fd) == -1)
			return (1);
	pid = fork();
	if (pid == 0)
		ms_execute_pipeline_child(lsa_command, state, pipe_fd, new_pipe_fd);
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
	waitpid(pid, &ret, 0);
	return (ret);
}

static void	ms_execute_pipeline_child(t_lsa_command *lsa_command,
		t_state_in_pipeline state, int *pipe_fd, int *new_pipe_fd)
{
	int	ret;

	if ((state & FIRST_COMMAND) == 0)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			exit(1);
		close(pipe_fd[0]);
	}
	if ((state & LAST_COMMAND) == 0)
	{
		close(new_pipe_fd[0]);
		if (dup2(new_pipe_fd[1], STDOUT_FILENO) == -1)
			exit(1);
		close(new_pipe_fd[1]);
	}
	ret = ms_simple_command_execution(lsa_command);
	exit(ret);
}
