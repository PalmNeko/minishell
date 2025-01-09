/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_import_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 13:46:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"

/**
 * import environment variable. this function effect to ms_getenv and ms_setenv
 * functions.
 * this function overwrite environment variable.
 * every element format: name=[value]
 * @param envp import target environment variable.
 * @return
 * 0: if succeed.
 * -1: if occurs an error. and set errno.
 * @exception
 * 	ENOMEM: have no enough memory.
 *  EINVAL: envp is not correct format.
 */
int	ms_import_env(char *const envp[])
{
	t_list		**internal_env;
	t_ms_var	*new_ms_var;
	t_list		*new_list;

	internal_env = ms_int_get_environ_variable();
	if (*internal_env != NULL)
		ft_lstclear(internal_env,
			(void (*)(void *))ms_int_destroy_ms_var);
	while (*envp != NULL)
	{
		new_ms_var = ms_int_generate_ms_var_from_text(*envp);
		if (new_ms_var == NULL)
			return (ft_lstclear(internal_env,
					(void (*)(void *))ms_int_destroy_ms_var), -1);
		new_list = ft_lstnew(new_ms_var);
		if (new_list == NULL)
		{
			ms_int_destroy_ms_var(new_ms_var);
			return (ft_lstclear(internal_env,
					(void (*)(void *))ms_int_destroy_ms_var), -1);
		}
		ft_lstadd_back(internal_env, new_list);
		envp++;
	}
	return (0);
}
