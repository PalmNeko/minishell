/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:13:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/27 17:13:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **lst)
{
	t_list	*first;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	first = ft_lstfirst(*lst);
	if (first == NULL)
		return (NULL);
	if (first->prev != NULL)
		first->prev->next = first->next;
	if (first->next != NULL)
		first->next->prev = first->prev;
	if (first->next == first)
		*lst = NULL;
	else
		*lst = first->next;
	first->prev = NULL;
	first->next = NULL;
	return (first);
}
