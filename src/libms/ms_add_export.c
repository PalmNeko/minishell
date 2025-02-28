/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:38:27 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 05:53:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

static t_list	*ms_find_export(const char *name);

/**
 * @brief Add an export variable.
 * @param name The name of the export variable.
 * @return 0 on success, -1 on error.
 */
int	ms_add_export(const char *name)
{
	t_list	*env_list;
	t_list	*newlst;
	char	*dupped_name;

	if (ms_find_export(name) != NULL)
		return (0);
	env_list = ms_get_exports();
	dupped_name = ft_strdup(name);
	if (dupped_name == NULL)
		return (-1);
	newlst = ft_lstnew(dupped_name);
	if (newlst == NULL)
	{
		free(dupped_name);
		return (-1);
	}
	ft_lstadd_back(&env_list, newlst);
	ms_set_exports(env_list);
	return (0);
}

static t_list	*ms_find_export(const char *name)
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
