/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:16:25 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/02 07:26:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include "ms_getopt.h"
#include "unset_internal_type.h"
#include <stddef.h>

static int	ms_parse_option_unset(t_builtin_unset *parsed, t_opting *opting);
static void	ms_print_usage_unset(void);

int	ms_builtin_unset(const char *path, char *const argv[], char *const envp[])
{
	int				status;
	int				index;
	int				argc;
	t_opting		opting;
	t_builtin_unset	parsed;

	(void)path;
	(void)envp;
	argc = (int)ms_ntpsize((void **)argv);
	ms_getopt_init(&opting, argc, (char **)argv, "");
	status = ms_parse_option_unset(&parsed, &opting);
	if (status != 0)
		return (status);
	index = 0;
	while (parsed.names[index] != NULL)
	{
		ms_unsetenv(parsed.names[index]);
		index++;
	}
	return (0);
}

static int	ms_parse_option_unset(t_builtin_unset *parsed, t_opting *opting)
{
	while (ms_getopt_parse(opting))
	{
		ms_perror_invalid_option("unset", opting->optopt);
		ms_print_usage_unset();
		return (2);
	}
	parsed->names = opting->argv + opting->optind;
	return (0);
}

static void	ms_print_usage_unset(void)
{
	ft_putendl_fd("unset: usage: unset [name ...]", 2);
}
