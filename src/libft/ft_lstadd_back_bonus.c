/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:12:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 16:18:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = ft_lstlast(*lst);
	if (last_list == NULL)
	{
		*lst = new;
		return ;
	}
	if (last_list->next != NULL)
		last_list->next->prev = new;
	new->next = last_list->next;
	new->prev = last_list;
	last_list->next = new;
	return ;
}
