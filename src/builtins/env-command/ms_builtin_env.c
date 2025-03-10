/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:31:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/05 13:05:35 by tookuyam         ###   ########.fr       */
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

int	ms_builtin_env(const char *path, char *const argv[], char *const envp[])
{
	int			status;
	int			argc;
	char		**environs;
	char		**head;
	t_opting	opting;

	(void)path;
	(void)envp;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "");
	status = ms_parse_builtin_env(&opting);
	if (status != 0)
		return (status);
	environs = ms_export_env();
	head = environs;
	while (head != NULL && *head != NULL)
	{
		printf("%s\n", *head);
		head++;
	}
	ms_destroy_ntp(environs);
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
