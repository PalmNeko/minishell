/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 17:19:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*itr;
	t_list	*free_lst;
	t_list	*start;

	if (lst == NULL || *lst == NULL)
		return ;
	itr = (*lst);
	if (itr->prev != NULL)
	{
		itr = itr->prev;
		itr->next->prev = NULL;
	}
	while (itr->prev != NULL)
		itr = itr->prev;
	start = itr;
	itr = itr->next;
	while (itr != NULL && itr != start)
	{
		free_lst = itr;
		itr = itr->next;
		ft_lstdelone(free_lst, del);
	}
	ft_lstdelone(start, del);
	*lst = NULL;
	return ;
}
