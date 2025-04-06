/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:50:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/06 12:56:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief Remove an export variable.
 * @param name The name of the export variable.
 * @return 0 on success.
 */
int	ms_remove_export(const char *name)
{
	t_list	*env_list;
	t_list	*target_lst;

	target_lst = ms_find_export(name);
	if (target_lst == NULL)
		return (1);
	env_list = ms_get_exports();
	ft_lstdel_content(&env_list, target_lst->content, free);
	ms_set_exports(env_list);
	return (0);
}
