/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:18:04 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/17 13:01:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "semantic_analyze.h"
#include "ms_execute_pipeline.h"
#include "execution.h"
#include "libms.h"

static int	ms_run_pipeline_command(t_lsa_pipeline *pipeline,
				int index, int pipe_fds[2][2], pid_t *pid_list);
static int	ms_run_pipeline_child(t_lsa_pipeline *pipeline,
				int index, int pipe_fds[2][2]);
static int	ms_run_pipeline_parent(t_lsa_pipeline *pipeline,
				int index, int pipe_fds[2][2]);
static int	ms_wait_for_children(pid_t *pid_list, int cmd_count);

int	ms_run_pipeline(t_lsa_pipeline *pipeline)
{
	int			index;
	const int	cmd_count = ms_count_ntp((void **)pipeline->commands);
	int			ret;
	int			pipe_fds[2][2];
	pid_t		*pid_list;

	pid_list = (pid_t *)malloc(sizeof(pid_t) * cmd_count);
	if (!pid_list)
		return (1);
	index = 0;
	while (pipeline->commands[index])
	{
		if (pipeline->commands[index + 1] != NULL
			&& pipe(pipe_fds[CURRENT_PIPE]) == -1)
			return (1);
		ret = ms_run_pipeline_command(pipeline, index, pipe_fds, pid_list);
		if (ms_has_meta(ret, IS_CHILD))
			return (ret);
		index++;
	}
	ret = ms_wait_for_children(pid_list, cmd_count);
	free(pid_list);
	return (ret);
}

static int	ms_run_pipeline_command(t_lsa_pipeline *pipeline, int index,
									int pipe_fds[2][2], pid_t *pid_list)
{
	int	ret;

	pid_list[index] = fork();
	if (pid_list[index] == 0)
	{
		ret = ms_run_pipeline_child(pipeline, index, pipe_fds);
		return (free(pid_list), ret);
	}
	else if (pid_list[index] == -1)
		return (1);
	ret = ms_run_pipeline_parent(pipeline, index, pipe_fds);
	return (ret);
}

static int	ms_run_pipeline_child(t_lsa_pipeline *pipeline,
				int index, int pipe_fds[2][2])
{
	int	ret;

	if (index != 0)
	{
		close(pipe_fds[BEFORE_PIPE][1]);
		if (dup2(pipe_fds[BEFORE_PIPE][0], STDIN_FILENO) == -1)
			return (1);
		close(pipe_fds[BEFORE_PIPE][0]);
	}
	if (pipeline->commands[index + 1] != NULL)
	{
		close(pipe_fds[CURRENT_PIPE][0]);
		if (dup2(pipe_fds[CURRENT_PIPE][1], STDOUT_FILENO) == -1)
			return (1);
		close(pipe_fds[CURRENT_PIPE][1]);
	}
	ret = ms_simple_command_execution(pipeline->commands[index]);
	ret = ms_add_meta(ret, IS_CHILD);
	return (ret);
}

static int	ms_run_pipeline_parent(t_lsa_pipeline *pipeline,
				int index, int pipe_fds[2][2])
{
	if (index != 0)
	{
		close(pipe_fds[BEFORE_PIPE][0]);
		close(pipe_fds[BEFORE_PIPE][1]);
	}
	if (pipeline->commands[index + 1] != NULL)
	{
		ft_memcpy(pipe_fds[BEFORE_PIPE], pipe_fds[CURRENT_PIPE],
			sizeof(int) * 2);
	}
	return (0);
}

static int	ms_wait_for_children(pid_t *pid_list, int cmd_count)
{
	int		status;
	int		i;

	i = 0;
	while (i < cmd_count)
	{
		waitpid(pid_list[i], &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}
	return (status);
}
