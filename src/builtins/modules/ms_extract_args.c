/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:34:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:40:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include "builtin_internal.h"
#include <stddef.h>

char	**ms_extract_args(char *const argv[])
{
	const char	**null_ntp;

	null_ntp = (const char *[]){NULL};
	if (argv[0] == NULL)
		return (ms_dup_ntp(null_ntp));
	argv++;
	while (*argv != NULL)
	{
		if (ft_strcmp(*argv, "--") == 0)
		{
			argv++;
			break ;
		}
		else if (ms_is_option(*argv) == false)
			break ;
		argv++;
	}
	return (ms_dup_ntp4(argv));
}
