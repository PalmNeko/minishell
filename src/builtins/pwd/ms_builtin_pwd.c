/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:53:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/07 11:41:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include "libft.h"
#include "libms.h"
#include "ms_getopt.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static void	ms_print_usage_pwd(void);

int	ms_builtin_pwd(
		const char *path, char *const argv[], char *const envp[])
{
	char		*cwd;
	t_opting	opting;
	int			argc;

	(void)path;
	(void)envp;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "");
	while (ms_getopt_parse(&opting))
	{
		ms_perror_invalid_option("pwd", opting.optopt);
		ms_print_usage_pwd();
		return (2);
	}
	cwd = ms_get_current_dir_name();
	if (cwd == NULL)
	{
		cwd = ms_get_cdwd();
		if (cwd != NULL)
			cwd = ft_strdup(cwd);
	}
	if (cwd != NULL)
		ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}

static void	ms_print_usage_pwd(void)
{
	ft_putendl_fd("pwd: usage: pwd", 2);
}
