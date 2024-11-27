/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewcircular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:55:03 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 13:57:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewcircular(void *content)
{
	t_list	*lst;

	lst = ft_lstnew(content);
	if (lst == NULL)
		return (NULL);
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}
