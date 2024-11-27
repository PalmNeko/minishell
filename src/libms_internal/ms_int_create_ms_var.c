/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_create_ms_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:57:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 16:13:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal_type.h"
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
	(void)name;
	(void)value;
	return (NULL);
}
