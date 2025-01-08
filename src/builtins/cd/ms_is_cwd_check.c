/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_cwd_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:34:13 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 14:34:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include <stdbool.h>

/**
 * return if below:
 *   command: cd
 *   option: -Pe
 */
bool	ms_is_cwd_check(char *const argv[])
{
	if (ms_has_opt(argv, 'e', "LPe") && ms_is_resolve_symlink(argv))
		return (true);
	return (false);
}
