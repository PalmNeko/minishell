/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:14:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/06 13:08:12 by tookuyam         ###   ########.fr       */
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
	stat_str = ft_itoa(status);
	ms_setenv("?", stat_str, 1);
	free(stat_str);
	return (0);
}
