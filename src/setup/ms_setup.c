/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:29:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 05:21:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "setup_internal.h"
#include "readline.h"

t_minishell	*ms_setup(void)
{
	t_minishell	*ms;

	ms_setup_variable();
	ms_setup_history();
	ms_setup_readline_behavior();
	ms_setup_global_variables();
	ms_setup_export_environ();
	ms = ms_get_minishell();
	*ms = (t_minishell){
		.ms_malloc_list = NULL,
		.ms_shell_var = NULL,
	};
	return (ms);
}
