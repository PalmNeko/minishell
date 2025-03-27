/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_exports.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/26 03:50:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

char	**ms_export_names(void)
{
	char	**names;
	t_list	*lst;
	t_list	*dupped_lst;

	lst = ms_get_exports();
	if (lst == NULL)
		return (ft_calloc(1, sizeof(char *)));
	dupped_lst = ft_lstmap(lst, (void *(*)(void *))ft_strdup, free);
	if (dupped_lst == NULL)
		return (NULL);
	names = ms_lst_to_ntp(&dupped_lst, ms_identify, ms_noop_del);
	if (names == NULL)
		return (ft_lstclear(&dupped_lst, free), NULL);
	return (names);
}
