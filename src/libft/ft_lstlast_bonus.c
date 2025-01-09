/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:08:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/12 15:21:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_prev;
	t_list	*itr;

	if (lst == NULL)
		return (NULL);
	tmp_prev = lst->prev;
	if (tmp_prev != NULL)
		lst->prev->next = NULL;
	itr = lst;
	while (itr->next != NULL)
		itr = itr->next;
	if (tmp_prev != NULL)
		tmp_prev->next = lst;
	return (itr);
}
