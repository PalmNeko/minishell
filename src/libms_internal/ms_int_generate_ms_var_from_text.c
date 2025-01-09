/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_generate_ms_var_from_text.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:53:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 14:29:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms_internal.h"
#include "libft.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * generate t_ms_var variable from formatted text.
 * @param text text for set value format: name=[value]
 * @return pointer to ms_var on success. Null on error and set errno.
 * @exception
 * ENOMEM: has no memory
 * EINVAL: text format is incorrect.
 */
t_ms_var	*ms_int_generate_ms_var_from_text(const char *text)
{
	char		*first_equal_ptr;
	char		*name;
	char		*value;
	t_ms_var	*ms_var;

	first_equal_ptr = ft_strchr(text, '=');
	if (first_equal_ptr == NULL || text == first_equal_ptr)
	{
		errno = EINVAL;
		return (NULL);
	}
	name = ft_strndup(text, first_equal_ptr - text);
	if (name == NULL)
		return (NULL);
	value = ft_strdup(first_equal_ptr + 1);
	if (value == NULL)
		return (free(name), NULL);
	ms_var = ms_int_create_ms_var(name, value);
	free(name);
	free(value);
	if (ms_var == NULL)
		return (NULL);
	return (ms_var);
}
