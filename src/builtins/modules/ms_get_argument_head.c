/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_argument_head.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:13:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 19:00:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include <stddef.h>

char	**ms_get_argument_head(char *const argv[], const char *valid_opts)
{
	if (argv[0] == NULL)
		return (NULL);
	argv++;
	while (*argv != NULL)
	{
		if (ms_validate_opts(*argv, valid_opts) == false)
			return ((char **)argv);
		argv++;
	}
	return ((char **)argv);
}
