/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exclude_valid_opts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:33:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:42:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "builtin_internal.h"
#include <stdlib.h>

char	**ms_exclude_valid_opts(char *const argv[], const char *valid_opts)
{
	char *const	*ntp_null;

	ntp_null = (char *const []){NULL};
	if (argv[0] == NULL)
		return (ms_dup_ntp4(ntp_null));
	argv++;
	while (*argv != NULL)
	{
		if (ms_validate_opts(*argv, valid_opts) == false)
			return (ms_dup_ntp4(argv));
		argv++;
	}
	return (ms_dup_ntp4(ntp_null));
}
