/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:22:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/16 20:36:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief delete by content address.
 * @param root root list. if root->content == content, update root address.
 * @param content pointer to content.
 * @param del delete function.
 * @return void
 */
void	ft_lstdel_content(t_list **root, void *content, void (*del)(void *))
{
	t_list	*itr;
	t_list	*new_root;

	itr = *root;
	while (itr != NULL)
	{
		if (itr->content == content)
		{
			if (itr == *root)
				new_root = (*root)->next;
			else
				new_root = (*root);
			*root = new_root;
			ft_lstdelone(itr, del);
			return ;
		}
		itr = itr->next;
	}
	return ;
}
