/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:51:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 18:06:37 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include "ms_execute_pipeline.h"
#include "memento/memento.h"
#include <stdlib.h>
#include <sys/wait.h>

static int	ms_alone_command_execution(t_lsa_pipeline *pipeline);
static int	ms_get_is_fork(t_lsa_command *lsa_command);

// when single cat , press Ctrl + C, exit minishell T_T
int	ms_execute_pipeline(t_lsa_pipeline *pipeline)
{
	int				ret;
	const size_t	cmd_len = ms_ntpsize((void **)pipeline->commands);

	if (cmd_len == 1)
		ret = ms_alone_command_execution(pipeline);
	else
		ret = ms_run_pipeline(pipeline);
	return (ret);
}

static int	ms_alone_command_execution(t_lsa_pipeline *pipeline)
{
	int					ret;
	int					is_fork;
	t_environ_memento	*env_memento;

	is_fork = ms_get_is_fork(pipeline->commands[0]);
	if (is_fork == 1)
		ret = ms_run_pipeline(pipeline);
	else if (is_fork == 0)
	{
		env_memento = ms_save_environ_memento();
		if (env_memento == NULL)
			return (1);
		ret = ms_simple_command_execution(pipeline->commands[0]);
		if (ms_restore_environ_memento(env_memento) == -1)
			ret = 1;
		ms_memento_destroy(env_memento);
	}
	else
	{
		return (1);
	}
	return (ret);
}

static int	ms_get_is_fork(t_lsa_command *lsa_command)
{
	char	**expanded_strings;
	int		is_fork;

	is_fork = 0;
	if (lsa_command->args != NULL)
	{
		expanded_strings = ms_expansion(lsa_command->args[0]);
		if (expanded_strings == NULL)
			return (-1);
		if (expanded_strings[0] && ms_isbuiltin(expanded_strings[0]) != 1)
			is_fork = 1;
		ms_destroy_ntp2((void **)expanded_strings, free);
	}
	return (is_fork);
}
