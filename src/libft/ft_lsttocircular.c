/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttocircluar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 16:41:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsttocircular(t_list *lst)
{
	t_list	*first;
	t_list	*last;

	first = ft_lstfirst(lst);
	last = ft_lstlast(lst);
	if (first == NULL || last == NULL)
		return ;
	first->prev = last;
	last->next = first;
	return ;
}
