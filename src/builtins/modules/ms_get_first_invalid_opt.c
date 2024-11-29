/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_first_invalid_opt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:12:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 19:36:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin_internal.h"
#include <stddef.h>

char	*ms_strunpbrk(const char *str, const char *accept);

char	*ms_get_first_invalid_opt(char *const argv[], const char *valid_opts)
{
	if (argv[0] == NULL)
		return (NULL);
	argv++;
	while (*argv != NULL)
	{
		if (ms_is_option(*argv)
			&& ms_validate_opts(*argv, valid_opts) == false)
		{
			return (ms_strunpbrk(*argv + 1, valid_opts));
		}
		else
			return (NULL);
		argv++;
	}
	return (NULL);
}

char	*ms_strunpbrk(const char *str, const char *accept)
{
	while (*str != '\0')
	{
		if (ft_strchr(accept, *str) == NULL)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
