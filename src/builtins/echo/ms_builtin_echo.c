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

#include "builtin_echo.h"
#include "libms.h"
#include "libft.h"
#include <stdlib.h>

int	ms_builtin_echo(const char *path, char *const argv[], char *const envp[])
{
	char			*joined;
	t_builtin_echo	parsed;

	ms_parse_builtin_echo_arg(&parsed, path, argv, envp);
	joined = ms_join_ntp((const char **)(argv + parsed.arg_index), " ");
	if (joined == NULL)
		return (0);
	if (parsed.is_n)
		ft_putstr_fd(joined, 1);
	else
		ft_putendl_fd(joined, 1);
	free(joined);
	return (0);
}
