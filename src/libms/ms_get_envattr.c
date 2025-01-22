/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_envattr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:18:47 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:43:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"

/**
 * get environment variable attribute.
 * @param name variable name
 * @return variable attributes on success. ATTR_NONE on variable is not found.
 */
t_ms_var_type	ms_get_envattr(const char *name)
{
	t_ms_var	*ms_var;

	ms_var = ms_find_ms_var(name);
	if (ms_var == NULL)
		return (ATTR_NONE);
	return (ms_var->attr);
}
