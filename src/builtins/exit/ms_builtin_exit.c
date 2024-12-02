/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:10:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/02 16:42:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

static int	ms_error_handling_exit(
				const char *path, char *const argv[], char *const envp[]);
static int	ms_calc_exit_status(
		const char *path, char *const argv[], char *const envp[]);
static int	ms_cleanup_and_exit_dummy(int status);

int	ms_builtin_exit(
		const char *path, char *const argv[], char *const envp[])
{
	int		exit_status;

	if (ms_get_interactive_stat() == 0)
		ft_putendl_fd("exit", 2);
	exit_status = ms_calc_exit_status(path, argv, envp);
	ms_cleanup_and_exit_dummy(exit_status);
	return (exit_status);
}

static int	ms_calc_exit_status(
		const char *path, char *const argv[], char *const envp[])
{
	int		status;
	char	*endptr;
	int		exit_status;
	char	**arg_head;

	status = ms_error_handling_exit(path, argv, envp);
	if (status != 0)
		return (status);
	arg_head = ms_get_argument_head(argv, "");
	if (arg_head == NULL)
		return (1);
	errno = 0;
	if (arg_head[0] != NULL && ft_strcmp(arg_head[0], "--") == 0)
		arg_head++;
	if (arg_head[0] == NULL)
		return (0);
	exit_status = ft_strtol(arg_head[0], &endptr, 10);
	if (endptr[0] != '\0'
		|| (arg_head[0][0] == '\0' && endptr[0] == '\0')
		|| errno != 0)
		return (ms_perror_cmd2(
				"exit", arg_head[0], "numeric argument required"), 2);
	return (exit_status);
}

static int	ms_cleanup_and_exit_dummy(int status)
{
	exit(status);
}

static int	ms_error_handling_exit(
		const char *path, char *const argv[], char *const envp[])
{
	char	**arg_head;
	char	*valid_opt;
	size_t	argc;

	(void)path;
	(void)envp;
	valid_opt = "";
	arg_head = ms_get_argument_head(argv, valid_opt);
	if (arg_head == NULL)
		return (1);
	if (arg_head[0] != NULL && ft_strcmp(arg_head[0], "--") == 0)
		arg_head++;
	argc = ms_ntpsize((void **)arg_head);
	if (argc > 1)
		return (ms_perror_cmd("exit", "too many arguments"), 1);
	return (0);
}
