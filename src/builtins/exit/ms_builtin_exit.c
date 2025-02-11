/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:10:41 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 07:38:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include "exit_internal.h"
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

static int	ms_cleanup_and_exit_dummy(int status);

int	ms_builtin_exit(
		const char *path, char *const argv[], char *const envp[])
{
	t_builtin_exit	parsed;
	int				status;

	(void)path;
	(void)envp;
	if (ms_get_interactive_stat() == 0)
		ft_putendl_fd("exit", 2);
	status = ms_parse_builtin_exit(&parsed, argv);
	if (status != 0)
		ms_cleanup_and_exit_dummy(status);
	else
		ms_cleanup_and_exit_dummy(parsed.exit_status);
	return (status);
}

static int	ms_cleanup_and_exit_dummy(int status)
{
	exit(status);
}
