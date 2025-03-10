/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:51:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/10 19:04:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include "ms_execute_pipeline.h"
#include <stdlib.h>
#include <sys/wait.h>

static int	ms_single_command_execution(t_lsa_pipeline *pipeline);

// cat単一の時にCtrl+Cを押すとminishellごと抜けてしまう
int	ms_execute_pipeline(t_lsa_pipeline *pipeline)
{
	int	ret;

	if (pipeline->commands[0]->args == NULL)
		ret = ms_simple_command_execution(pipeline->commands[0]);
	else if (pipeline->commands[1] == NULL)
	{
		ret = ms_single_command_execution(pipeline);
	}
	else
		ret = ms_run_pipeline(pipeline);
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
		ret = ms_run_pipeline(pipeline);
	ms_destroy_ntp2((void **)expanded_strings, free);
	return (ret);
}
