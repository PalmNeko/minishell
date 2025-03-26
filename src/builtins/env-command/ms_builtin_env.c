/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:31:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/26 03:50:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "ms_getopt.h"
#include "builtin_internal.h"
#include <stddef.h>
#include <stdio.h>

static int	ms_parse_builtin_env(t_opting *opting);
static void	ms_print_usage_env(void);
static void	ms_print_environ(void);

int	ms_builtin_env(const char *path, char *const argv[], char *const envp[])
{
	int			status;
	int			argc;
	t_opting	opting;

	(void)path;
	(void)envp;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "");
	status = ms_parse_builtin_env(&opting);
	if (status != 0)
		return (status);
	ms_print_environ();
	return (0);
}

static int	ms_parse_builtin_env(t_opting *opting)
{
	while (ms_getopt_parse(opting))
	{
		ms_perror_invalid_option("env", opting->optopt);
		ms_print_usage_env();
		return (2);
	}
	if (opting->argv[opting->optind] != NULL)
	{
		ms_perror_cmd("env", "too many arguments");
		return (1);
	}
	return (0);
}

static void	ms_print_usage_env(void)
{
	ft_putendl_fd("env: usage: env", 2);
}

static void	ms_print_environ(void)
{
	char	**names;
	char	*value;

	names = ms_export_names();
	if (names == NULL)
		return ;
	while (*names != NULL)
	{
		value = ms_getenv(*names);
		if (value != NULL)
			printf("%s=%s\n", *names, value);
		names++;
	}
	ms_destroy_ntp(names);
}
