/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:04:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 15:07:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*itr;
	t_list	*start;
	int		size;

	start = ft_lstfirst(lst);
	if (start == NULL)
		return (0);
	if (start->prev != NULL)
		start->prev->next = NULL;
	itr = start;
	size = 0;
	while (itr != NULL)
	{
		size += 1;
		itr = itr->next;
	}
	if (start->prev != NULL)
		start->prev->next = start;
	return (size);
}
