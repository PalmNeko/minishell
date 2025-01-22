/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_ms_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:11:03 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 08:44:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"

t_ms_var	*ms_find_ms_var(const char *name)
{
	t_list		**environ_lst;
	t_list		*itr;
	t_ms_var	*ms_var;

	environ_lst = ms_int_get_environ_variable();
	itr = *environ_lst;
	while (itr != NULL)
	{
		ms_var = itr->content;
		if (ft_strcmp(ms_var->name, name) == 0)
			return (ms_var);
		itr = itr->next;
	}
	return (NULL);
}
