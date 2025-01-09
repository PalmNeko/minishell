/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:16:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/30 19:16:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include <stddef.h>

static int	ms_error_handling_unset(
				const char *path, char *const argv[], char *const envp[]);
static void	ms_print_usage_unset(void);

int	ms_builtin_unset(const char *path, char *const argv[], char *const envp[])
{
	int		status;
	char	**arg_head;

	status = ms_error_handling_unset(path, argv, envp);
	if (status != 0)
		return (status);
	arg_head = ms_get_argument_head(argv, "");
	if (arg_head == NULL)
		return (1);
	if (*arg_head != NULL && ft_strcmp(*arg_head, "--") == 0)
		arg_head++;
	while (*arg_head != NULL)
	{
		ms_unsetenv(*arg_head);
		arg_head++;
	}
	return (0);
}

int	ms_error_handling_unset(
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
		ms_perror_cmd2("unset", opt_txt, "invalid option");
		ms_print_usage_unset();
		return (2);
	}
	return (0);
}

static void	ms_print_usage_unset(void)
{
	ft_putendl_fd("unset: usage: unset [name ...]", 2);
}
