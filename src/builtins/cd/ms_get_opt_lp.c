/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_opt_lp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:19:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include <stddef.h>

char	*ms_get_opt_lp(char *const argv[])
{
	char	*opt;
	size_t	index;
	size_t	inner;

	index = 0;
	if (argv[0] == NULL)
		return (NULL);
	argv++;
	opt = NULL;
	while (ms_validate_opts(argv[index], "LPe"))
	{
		inner = 1;
		while (argv[index][inner] != '\0')
		{
			if (argv[index][inner] == 'L' || argv[index][inner] == 'P')
				opt = argv[index] + inner;
			inner++;
		}
		index++;
	}
	return (opt);
}
