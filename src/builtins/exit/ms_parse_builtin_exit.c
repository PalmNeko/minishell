/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_builtin_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:37:20 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/06 12:30:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ms_getopt.h"
#include "exit_internal.h"
#include "libms.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>

static bool	ms_is_numeric(const char *str, const char *endptr);

int	ms_parse_builtin_exit(t_builtin_exit *parsed, char *const argv[])
{
	int			status;
	char		*endptr;
	int			idx;
	char		*str;

	idx = 1;
	if (argv[idx] != NULL && ft_strcmp(argv[idx], "--") == 0)
		idx++;
	if (argv[idx] == NULL)
		str = ms_getenv("?");
	else
		str = argv[idx];
	if (str == NULL)
		return (ms_perror_cmd("exit", "not set `?' variable"), 1);
	errno = 0;
	status = ft_strtol(str, &endptr, 10);
	if (ms_is_numeric(str, endptr) == false || errno != 0)
		return (ms_perror_cmd2("exit", str, "numeric argument required"), 2);
	if (ms_ntpsize((void **)(argv + idx)) > 1)
	{
		parsed->is_exit = false;
		return (ms_perror_cmd("exit", "too many arguments"), 1);
	}
	parsed->exit_status = status;
	return (0);
}

static bool	ms_is_numeric(const char *str, const char *endptr)
{
	if (endptr[0] != '\0')
		return (false);
	if (str[0] == '\0' && endptr[0] == '\0')
		return (false);
	return (true);
}
