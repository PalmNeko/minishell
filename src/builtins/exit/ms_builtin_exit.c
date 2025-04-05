/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:10:41 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/05 13:44:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include "exit_internal.h"
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

int	ms_builtin_exit(
		const char *path, char *const argv[], char *const envp[])
{
	t_builtin_exit	parsed;
	int				status;

	(void)path;
	(void)envp;
	status = ms_parse_builtin_exit(&parsed, argv);
	if (status != 0)
		status = ms_add_meta(status, IS_EXIT);
	else
		status = ms_add_meta(parsed.exit_status, IS_EXIT);
	return (status);
}
