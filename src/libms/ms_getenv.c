/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:55:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:20:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include <stddef.h>

/**
 * get value of name from now environment.
 * @param name name of environment variable
 * @return  pointer to environment value address if succeeded.
 * null-pointer if occurs an error.
 * @note
 * you mustn't release return value.
 */
char	*ms_getenv(const char *name)
{
	t_list		**internal_env;
	t_list		*itr;
	t_ms_var	*ms_var;

	if (ms_int_import_on_initial() == -1)
		return (NULL);
	internal_env = ms_int_get_environ_variable();
	itr = *internal_env;
	while (itr != NULL)
	{
		ms_var = itr->content;
		if (ft_strcmp(ms_var->name, name) == 0)
			return (ms_var->value);
		itr = itr->next;
	}
	return (NULL);
}
