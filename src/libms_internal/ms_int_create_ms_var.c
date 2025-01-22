/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_create_ms_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:57:57 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:10:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal.h"
#include "libft.h"
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

/**
 * generate t_ms_var variable.
 * @param name
 * @return pointer to ms_var on success. Null on error and set errno.
 * @exception
 * ENOMEM: has no memory
 * EINVAL: text format is incorrect.
 */
t_ms_var	*ms_int_create_ms_var(const char *name, const char *value)
{
	t_ms_var	*new_var;

	if (ms_int_validate_env_name(name) == false)
	{
		errno = EINVAL;
		return (NULL);
	}
	new_var = ft_calloc(1, sizeof(t_ms_var));
	if (new_var == NULL)
		return (NULL);
	new_var->name = ft_strdup(name);
	if (new_var->name == NULL)
		return (ms_int_destroy_ms_var(new_var), NULL);
	new_var->value = ft_strdup(value);
	if (new_var->value == NULL)
		return (ms_int_destroy_ms_var(new_var), NULL);
	new_var->attr = ATTR_NONE;
	return (new_var);
}
