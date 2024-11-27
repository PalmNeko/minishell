/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 15:03:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*itr;
	t_list	*prev_temp;

	if (lst == NULL)
		return (NULL);
	if (lst->prev == NULL)
		return (lst);
	prev_temp = lst->prev;
	lst->prev = NULL;
	itr = prev_temp;
	while (itr->prev != NULL)
		itr = itr->prev;
	lst->prev = prev_temp;
	return (itr);
}
