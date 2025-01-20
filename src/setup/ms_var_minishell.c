/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_var_minishell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 06:51:12 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 11:19:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static t_minishell	g_minishell;

void	ms_set_minishell(t_minishell *ms)
{
	g_minishell = *ms;
}

t_minishell	*ms_get_minishell(void)
{
	return (&g_minishell);
}
