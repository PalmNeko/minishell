/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:43:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/16 15:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (lst == NULL)
		return ;
	if (lst->prev != NULL)
		lst->prev->next = NULL;
	iter = lst;
	while (iter != NULL)
	{
		f(iter->content);
		iter = iter->next;
	}
	if (lst->prev != NULL)
		lst->prev->next = lst;
	return ;
}
