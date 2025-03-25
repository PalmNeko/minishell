/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:31:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 05:44:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

t_list	*ms_find_export(const char *name)
{
	t_list	*envlst;

	envlst = ms_get_exports();
	while (envlst != NULL)
	{
		if (ft_strcmp(envlst->content, name) == 0)
			return (envlst);
		envlst = envlst->next;
	}
	return (NULL);
}
