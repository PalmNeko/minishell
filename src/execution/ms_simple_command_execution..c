/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_simple_command_execution..c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:31:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 15:00:22 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>

static int	ms_simple_command_execution_with_args(t_lsa_command *lsa_command);
static int	ms_simple_command_execution_no_args(t_lsa_command *lsa_command);

int	ms_simple_command_execution(t_lsa_command *lsa_command)
{
	int	ret;

	ret = 0;
	if (lsa_command->args)
	{
		ret = ms_simple_command_execution_with_args(lsa_command);
	}
	else
	{
		ret = ms_simple_command_execution_no_args(lsa_command);
	}
	return (ret);
}

static int	ms_simple_command_execution_with_args(t_lsa_command *lsa_command)
{
	char	**args;
	int		ret;

	// t_environ_memento *memento;
	args = ms_expand_commands(lsa_command->args);
	// memento = ms_save_exec_memento(char *const envp[]);
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
