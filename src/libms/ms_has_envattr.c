/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_has_envattr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:19:56 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:44:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include <stdbool.h>

/**
 * has environment variable attribute.
 * @param name variable name
 * @param attr attribute
 * @return true on has any attr attributes. false on not found or not has attr.
 */
bool	ms_has_envattr(const char *name, t_ms_var_type attr)
{
	t_ms_var	*ms_var;

	ms_var = ms_find_ms_var(name);
	if (ms_var == NULL)
		return (false);
	if (ms_var->attr == attr || ms_var->attr & attr)
		return (true);
	return (false);
}
