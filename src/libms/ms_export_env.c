/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:54:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:17:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include "libms.h"
#include <stddef.h>

extern char	**environ;

/**
 * export environ variable
 * @return null terminated string following line format.
 * line format: name=[value]
 * @exception
 * ENOMEM: has no memory
 */
char	**ms_export_env(void)
{
	size_t	lstsize;
	size_t	index;
	t_list	*itr;
	t_list	**env_list;
	char	**env_ntp;

	if (ms_int_import_on_initial() == -1)
		return (NULL);
	env_list = ms_int_get_environ_variable();
	lstsize = ft_lstsize(*env_list);
	env_ntp = (char **)ft_calloc(lstsize + 1, sizeof(char *));
	if (env_ntp == NULL)
		return (NULL);
	index = 0;
	itr = *env_list;
	while (itr != NULL && index < lstsize)
	{
		env_ntp[index] = ms_int_ms_var_to_string(itr->content);
		if (env_ntp[index] == NULL)
			return (ms_destroy_ntp(env_ntp), NULL);
		index++;
		itr = itr->next;
	}
	env_ntp[index] = NULL;
	return (env_ntp);
}
