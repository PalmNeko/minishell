/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:12:42 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 18:03:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;
	t_list	*newlst_last;

	last_list = ft_lstlast(*lst);
	if (last_list == NULL)
	{
		*lst = new;
		return ;
	}
	newlst_last = ft_lstlast(new);
	if (last_list->next != NULL)
	{
		newlst_last->next = last_list->next;
		last_list->next->prev = newlst_last;
	}
	new->prev = last_list;
	last_list->next = new;
	return ;
}
