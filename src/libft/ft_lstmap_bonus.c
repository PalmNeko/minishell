/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:51:07 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/17 15:53:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static t_list	*_ft_lstmap(
					t_list *lst,
					t_list *tmp_head,
					void *(*f)(void *),
					void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_map;
	t_list	*ret_map;
	t_list	*tmp_prev;

	if (lst == NULL)
		return (NULL);
	head_map = ft_lstnew(NULL);
	tmp_prev = lst->prev;
	if (tmp_prev != NULL)
		tmp_prev->next = NULL;
	if (_ft_lstmap(lst, head_map, f, del) == NULL)
		ft_lstclear(&head_map, del);
	ret_map = head_map->next;
	ft_lstdelone(head_map, del);
	if (tmp_prev != NULL)
		tmp_prev->next = lst;
	return (ret_map);
}

static t_list	*_ft_lstmap(
			t_list *lst,
			t_list *tmp_head,
			void *(*f)(void *),
			void (*del)(void *))
{
	t_list	*map_lst;
	t_list	*new_lst;
	t_list	*itr;
	void	*tmp;

	map_lst = tmp_head;
	itr = lst;
	while (itr != NULL)
	{
		tmp = f(itr->content);
		new_lst = ft_lstnew(tmp);
		if (new_lst == NULL)
		{
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&map_lst, new_lst);
		map_lst = new_lst;
		itr = itr->next;
	}
	return (tmp_head);
}
