/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:02:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 16:17:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*first;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	first = ft_lstfirst(*lst);
	if (first->prev != NULL)
		first->prev->next = new;
	new->prev = first->prev;
	new->next = first;
	first->prev = new;
	if (*lst == first)
		*lst = new;
	return ;
}
