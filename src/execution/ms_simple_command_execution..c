/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_simple_command_execution..c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:31:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/03 10:00:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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
	// ret = ms_run_assignmen_variables(lsa_command->assignments);
	// ret = ms_run_redirects(lsa_command->redirects);
	ret = ms_execute_command(args);
	return (ret);
}

static int	ms_simple_command_execution_no_args(t_lsa_command *lsa_command)
{
	int	ret;

	(void)lsa_command;
	ret = 0;
	// if(lsa_command->assignments)
	// 	ret = ms_overwrite_environ(lsa_command->assignments);
	return (ret);
}
