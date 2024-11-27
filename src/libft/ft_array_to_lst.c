/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:48:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/17 16:04:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief array to list in memory.
 * @param array array values.
 * @param size array size.
 * @attention content is not allocated.
 * please free with ft_lstclear(&return_value, (void (*)(void *))ft_nop);
 * @return root list.
*/
t_list	*ft_array_to_lst(void **array, size_t size)
{
	size_t	index;
	t_list	*root;
	t_list	*iter;
	t_list	*tmp;

	root = NULL;
	if (size == 0)
		return (NULL);
	root = ft_lstnew(array[0]);
	iter = root;
	index = 1;
	while (index < size)
	{
		tmp = ft_lstnew(array[index]);
		if (tmp == NULL)
		{
			ft_lstclear(&root, (void (*)(void *))ft_voidnop);
			return (NULL);
		}
		ft_lstadd_back(&iter, tmp);
		iter = tmp;
		index++;
	}
	return (root);
}
