/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:25:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/27 17:25:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list, int no)
{
	int		index;
	t_list	*first;

	first = ft_lstfirst(list);
	list = first;
	index = 0;
	while (index < no)
	{
		if (list == NULL)
			return (NULL);
		list = list->next;
		index++;
	}
	if (list != NULL)
		return (list);
	return (NULL);
}
