/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/25 20:04:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include "ms_getopt.h"
#include "export_internal.h"
#include "builtin_internal.h"

static int	ms_error_handling_export(
				t_builtin_export *parsed,
				const char *path,
				char *const argv[],
				char *const envp[]);
static void	ms_print_export_usage(void);

int	ms_builtin_export(
				const char *path, char *const argv[], char *const envp[])
{
	int					status;
	t_builtin_export	parsed;

	status = ms_error_handling_export(&parsed, path, argv, envp);
	if (status != 0)
		return (status);
	if (parsed.is_print)
		return (ms_export_print_command());
	else
		return (ms_export_variables((const char **)parsed.names));
	return (0);
}

static int	ms_error_handling_export(
				t_builtin_export *parsed,
				const char *path,
				char *const argv[],
				char *const envp[])
{
	int			argc;
	t_opting	opting;

	(void)path;
	(void)envp;
	parsed->is_print = false;
	parsed->names = NULL;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "");
	while (ms_getopt_parse(&opting))
	{
		ms_perror_invalid_option("export", opting.optopt);
		ms_print_export_usage();
		return (2);
	}
	parsed->names = opting.argv + opting.optind;
	if (parsed->names[0] == NULL)
		parsed->is_print = true;
	else
		parsed->is_print = false;
	return (0);
}

static void	ms_print_export_usage(void)
{
	ft_putendl_fd("export: usage: export [name[=value] ...]", 2);
}
