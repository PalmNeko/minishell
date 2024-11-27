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

#include "ms_int_echo.h"
#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int	ms_builtin_echo(const char *path, char *const argv[], char *const envp[])
{
	int		index;
	char	*joined;

	(void)path;
	(void)envp;
	if (argv[0] == NULL)
		return (0);
	index = 1;
	while (argv[index] != NULL && ft_strcmp(argv[index], "-n") == 0)
		index++;
	joined = ms_join_ntp(&argv[index], " ");
	if (joined == NULL)
		return (0);
	ft_putstr_fd(joined, 1);
	if (! ms_has_opt(argv, "-n"))
		ft_putchar_fd('\n', 1);
	free(joined);
	return (0);
}
