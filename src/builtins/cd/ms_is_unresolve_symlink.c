/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_unresolve_symlink.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:42:16 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 18:42:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_internal.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_is_unresolve_symlink(char *const argv[])
{
	char	*opt;

	opt = ms_get_opt_lp(argv);
	if (opt == NULL || *opt == 'L')
		return (true);
	return (false);
}
