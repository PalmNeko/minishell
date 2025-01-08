/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_resolve_symlink.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:41:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 18:41:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_internal.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_is_resolve_symlink(char *const argv[])
{
	char	*opt;

	opt = ms_get_opt_lp(argv);
	if (*opt == 'P')
		return (true);
	return (false);
}
