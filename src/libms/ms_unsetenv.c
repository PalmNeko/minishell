/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:53:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:18:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include <errno.h>

/**
 * unset environment variable.
 * If  name does not exist in the environment, then the function succeeds, and
 * the environment is unchanged.
 * @param name variable name
 * @return zero on success. -1 on error, with errno set.
 * @exception
 * ENOMEM: has no memory.
 * EINVAL: name is NULL, points to a string of length 0, or contains an '='
 * character.
 */
int	ms_unsetenv(const char *name)
{
	t_list		**env_list;
	t_list		*itr;
	t_ms_var	*ms_var;

	if (ms_int_import_on_initial() == -1)
		return (-1);
	if (ms_int_validate_env_name(name) == false)
	{
		errno = EINVAL;
		return (-1);
	}
	env_list = ms_int_get_environ_variable();
	itr = *env_list;
	while (itr != NULL)
	{
		ms_var = itr->content;
		if (ft_strcmp(ms_var->name, name) == 0)
		{
			ft_lstdel_content(env_list, ms_var,
				(void (*)(void *))ms_int_destroy_ms_var);
			return (0);
		}
		itr = itr->next;
	}
	return (0);
}
