/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_envattr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:22:43 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:44:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"

/**
 * remove environment variable attribute.
 * @param name variable name
 * @param attr attribute
 * @return zero on success. -1 on variable is not found.
 */
int	ms_remove_envattr(const char *name, t_ms_var_type attr)
{
	t_ms_var	*ms_var;

	ms_var = ms_find_ms_var(name);
	if (ms_var == NULL)
		return (-1);
	ms_var->attr &= ~attr;
	return (0);
}
