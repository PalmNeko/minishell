/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_invalid_opts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:18:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 18:09:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin_internal.h"
#include <stdbool.h>
#include <stddef.h>

char	*ms_get_invalid_opts(const char *opts, const char *valid_opts)
{
	bool	opts_map[256];
	bool	valid_opts_map[256];
	size_t	index;

	ft_memset(opts_map, false, 256);
	ft_memset(valid_opts_map, false, 256);
	ms_set_character_map(opts, opts_map);
	ms_set_character_map(valid_opts, valid_opts_map);
	index = 0;
	while (index < 256)
	{
		if (opts_map[index] == true && valid_opts_map[index] == true)
			opts_map[index] = false;
		index++;
	}
	return (ms_create_string_from_map(opts_map));
}
