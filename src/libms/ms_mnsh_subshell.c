/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_mnsh_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 06:38:24 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/28 06:57:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	g_mnsh_subshell_var_enabled = true;

bool	ms_is_mnsh_subshell_var_enabled(void)
{
	return (g_mnsh_subshell_var_enabled);
}

void	ms_set_mnsh_subshell_var_enabled(bool enable)
{
	g_mnsh_subshell_var_enabled = enable;
}
