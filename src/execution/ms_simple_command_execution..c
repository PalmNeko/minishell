/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_simple_command_execution..c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:31:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/19 12:13:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "memento/memento.h"
#include <stdlib.h>

static int	ms_simple_command_execution_with_args(t_lsa_command *lsa_command);
static int	ms_simple_command_execution_no_args(t_lsa_command *lsa_command);

int	ms_simple_command_execution(t_lsa_command *lsa_command)
{
	int					ret;
	t_environ_memento	*env_memento;

	ret = 0;
	env_memento = ms_save_environ_memento();
	if (env_memento == NULL)
		return (1);
	if (lsa_command->args)
	{
		ret = ms_simple_command_execution_with_args(lsa_command);
	}
	else
	{
		ret = ms_simple_command_execution_no_args(lsa_command);
	}
	if (ms_restore_environ_memento(env_memento) == -1)
		ret = 1;
	ms_memento_destroy(env_memento);
	return (ret);
}

static int	ms_simple_command_execution_with_args(t_lsa_command *lsa_command)
{
	char	**args;
	int		ret;

	args = ms_expand_commands(lsa_command->args);
	if (args == NULL)
		return (1);
	if (lsa_command->assignments)
		ret = ms_run_assignment_variables(lsa_command->assignments);
	if (lsa_command->redirects)
		ret = ms_run_redirects(lsa_command->redirects);
	ret = ms_execute_command(args);
	ms_destroy_ntp2((void **)args, free);
	return (ret);
}

static int	ms_simple_command_execution_no_args(t_lsa_command *lsa_command)
{
	int	ret;

	(void)lsa_command;
	ret = 0;
	if (lsa_command->assignments)
		ret = ms_run_assignment_variables(lsa_command->assignments);
	if (lsa_command->redirects)
		ret = ms_run_redirects(lsa_command->redirects);
	return (ret);
}
