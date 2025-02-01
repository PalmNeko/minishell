/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:53:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/01 08:46:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include "libft.h"
#include "libms.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static void	ms_print_usage_pwd(void);

int	ms_builtin_pwd(
		const char *path, char *const argv[], char *const envp[])
{
	char	**arg_head;
	char	*invalid_opt;
	char	*cwd;
	char	opt_txt[3];

	(void)path;
	(void)envp;
	arg_head = ms_get_argument_head(argv, "");
	if (arg_head == NULL)
		return (1);
	invalid_opt = ms_get_first_invalid_opt(argv, "");
	if (invalid_opt != NULL)
	{
		ms_set_opt_txt(opt_txt, invalid_opt[0]);
		ms_perror_cmd2("pwd", opt_txt, "invalid option");
		ms_print_usage_pwd();
		return (2);
	}
	cwd = ms_get_current_dir_name();
	if (cwd == NULL)
		cwd = ms_get_cdwd();
	if (cwd != NULL)
		printf("%s\n", cwd);
	free(cwd);
	return (0);
}

static void	ms_print_usage_pwd(void)
{
	ft_putendl_fd("pwd: usage: pwd", 2);
}
