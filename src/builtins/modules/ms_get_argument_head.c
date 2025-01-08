/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_argument_head.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:13:44 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/08 12:14:19 by rnakatan         ###   ########.fr       */
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
