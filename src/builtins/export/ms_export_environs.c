/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_environs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:13:49 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 06:16:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <stdlib.h>

char	**ms_export_environs(void)
{
	char	**envptr;
	t_list	*export_list;
	size_t	lstsize;
	size_t	index;

	export_list = ms_get_exports();
	if (export_list == NULL)
		return (NULL);
	lstsize = ft_lstsize(export_list);
	envptr = ft_calloc((lstsize + 1), sizeof(char *));
	if (envptr == NULL)
		return (NULL);
	index = 0;
	while (index < lstsize)
	{
		envptr[index] = ft_strdup(export_list->content);
		if (envptr[index] == NULL)
			return (ms_destroy_ntp(envptr), NULL);
		export_list = export_list->next;
		index++;
	}
	return (envptr);
}
