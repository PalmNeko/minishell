/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:31:02 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/30 20:15:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include <stddef.h>
#include <stdio.h>

static int	ms_error_handling_env(
				const char *path, char *const argv[], char *const envp[]);
static void	ms_print_usage_env(void);

int	ms_builtin_env(const char *path, char *const argv[], char *const envp[])
{
	int		status;
	char	**arg_head;

	status = ms_error_handling_env(path, argv, envp);
	if (status != 0)
		return (status);
	arg_head = ms_get_argument_head(argv, "");
	if (arg_head == NULL)
		return (1);
	while (envp != NULL && *envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
	return (0);
}

int	ms_error_handling_env(
		const char *path, char *const argv[], char *const envp[])
{
	char	**arg_head;
	char	*invalid_opt;
	char	*valid_opt;
	char	opt_txt[3];

	(void)path;
	(void)envp;
	valid_opt = "";
	arg_head = ms_get_argument_head(argv, valid_opt);
	if (arg_head == NULL)
		return (1);
	invalid_opt = ms_get_first_invalid_opt(argv, valid_opt);
	if (invalid_opt != NULL)
	{
		ms_set_opt_txt(opt_txt, invalid_opt[0]);
		ms_perror_cmd2("env", opt_txt, "invalid option");
		ms_print_usage_env();
		return (2);
	}
	return (0);
}

static void	ms_print_usage_env(void)
{
	ft_putendl_fd("env: usage: env", 2);
}
