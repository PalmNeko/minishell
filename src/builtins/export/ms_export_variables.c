/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:04:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 05:54:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static int		ms_export_variable(const char *arg);

/**
 * @brief Export variables.
 */
int	ms_export_variables(const char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		ms_export_variable(args[i]);
		i++;
	}
	return (0);
}

static int	ms_export_variable(const char *arg)
{
	char	*dupped_arg;
	char	*equal_ptr;

	dupped_arg = ft_strdup(arg);
	if (dupped_arg == NULL)
		return (-1);
	equal_ptr = ft_strchr(dupped_arg, '=');
	if (equal_ptr != NULL)
	{
		*equal_ptr = '\0';
		if (ms_setenv(dupped_arg, equal_ptr + 1, 1) == -1)
		{
			free(dupped_arg);
			return (-1);
		}
	}
	ms_add_export(dupped_arg);
	free(dupped_arg);
	return (0);
}
