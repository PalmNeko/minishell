/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lstappend_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:07:22 by nyts              #+#    #+#             */
/*   Updated: 2025/02/19 17:08:20 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ms_lstappend_tail(t_list **lst, void *contents, void (*fr)(void *))
{
	t_list	*new;

	new = ft_lstnew(contents);
	if (new == NULL)
	{
		ft_lstclear(lst, fr);
		return ;
	}
	ft_lstadd_back(lst, new);
}

// int ms_lst_append_tail2(t_list **lst, void *contents, void (*fr)(void *))
// {
// 	t_list *new;

// 	new = ft_lstnew(contents);
// 	if (new == NULL)
// 	{
// 		ft_lstclear(lst, fr);
// 		return (-1);
// 	}
// 	ft_lstadd_back(lst, new);
// 	return (0);
// }
