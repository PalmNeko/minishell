/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_has_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:52:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:35:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include <stddef.h>
#include <stdbool.h>

bool	ms_has_opts(const char *opts, const char *check_opts)
{
	if (opts == NULL || check_opts == NULL)
		return (false);
	else if (ms_strpbrk(opts, check_opts) != NULL)
		return (true);
	else
		return (false);
}
