/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:25:15 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/08 12:19:03 by rnakatan         ###   ########.fr       */
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
