/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:30:58 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 06:20:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @attention this function is happened to memory leak at ft_lstdelone.
 */
int	ms_remove_export(const char *name)
{
	t_list	*env_target;

	env_target = ms_find_export(name);
	if (env_target == NULL)
		return (0);
	ft_lstdelone(env_target, free);
	return (0);
}
