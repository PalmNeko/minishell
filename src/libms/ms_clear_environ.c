/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clear_environ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:06:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:20:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"

/**
 * release internal memory for environment.
 * @param unused not used. you will always set NULL.
 * @note
 * if you even once use ms_export_env, ms_import_env, ms_getenv, ms_setenv
 * or ms_unsetenv, you must call this function.
 */
void	ms_clear_environ(void *unused)
{
	t_list	**env_list;

	(void)unused;
	env_list = ms_int_get_environ_variable();
	ft_lstclear(env_list, (void (*)(void *))ms_int_destroy_ms_var);
}
