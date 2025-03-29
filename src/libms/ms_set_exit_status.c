/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:14:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/29 12:38:02 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline.h>
#include <stdlib.h>
#include "libft.h"
#include "libms.h"

/**
 * set minishell's exit status.
 * -> insert $?
 */


int	ms_set_exit_status(int ret)
{
	char	*stat_str;
	int		status;

	status = ms_get_status_from_meta(ret);
	if (g_rl_is_sigint)
		status += 128 + SIGINT;
	stat_str = ft_itoa(status);
	ms_setenv("?", stat_str, 1);
	free(stat_str);
	return (0);
}
