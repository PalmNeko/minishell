/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_validate_opts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:35:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 13:40:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_validate_opts(const char *opt_arg, const char *valid_opts)
{
	bool	opts_map[256];
	bool	vopts_map[256];
	size_t	index;

	if (ms_is_option(opt_arg) == false)
		return (false);
	ms_set_character_map(opt_arg + 1, opts_map);
	ms_set_character_map(valid_opts, vopts_map);
	index = 0;
	while (index < 256)
	{
		if (opts_map[index] == true && opts_map[index] != vopts_map[index])
			return (false);
		index++;
	}
	return (true);
}
