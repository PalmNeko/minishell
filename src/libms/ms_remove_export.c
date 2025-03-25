/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:30:58 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 05:48:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief Add an export variable.
 * @param name The name of the export variable.
 * @return 0 on success, -1 on error.
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
