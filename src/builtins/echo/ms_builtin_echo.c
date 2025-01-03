/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:56:16 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/15 19:56:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "builtin_internal.h"
#include "libms.h"
#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int	ms_builtin_echo(const char *path, char *const argv[], char *const envp[])
{
	char	*joined;
	char	**arg_head;

	(void)path;
	(void)envp;
	if (argv[0] == NULL)
		return (0);
	arg_head = ms_get_argument_head(argv, "n");
	if (arg_head == NULL)
		return (0);
	joined = ms_join_ntp((const char **)arg_head, " ");
	if (joined == NULL)
		return (0);
	ft_putstr_fd(joined, 1);
	if (! ms_has_opt(argv, 'n', "n"))
		ft_putchar_fd('\n', 1);
	free(joined);
	return (0);
}
