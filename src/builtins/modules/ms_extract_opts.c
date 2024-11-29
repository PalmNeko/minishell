/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_opts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:47:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:54:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

char	*ms_extract_opts(char *const argv[])
{
	bool	set[256];

	if (argv[0] != NULL)
		argv++;
	ft_memset(set, 0, sizeof(set));
	while (*argv != NULL && ms_is_option(*argv) == true)
	{
		ms_set_character_map(*argv + 1, set);
		argv++;
	}
	return (ms_create_string_from_map(set));
}
