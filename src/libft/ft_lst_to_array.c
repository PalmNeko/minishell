/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:39:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 14:26:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief t_list to array in memory.
 * @param lst t_list argument.
 * @param size will set array size.
 * @note content is not deep copy.
 * please free with free(return_value);
 * @return first pointer to array in memory.
*/
void	**ft_lst_to_array(t_list *lst, size_t *ret_size)
{
	size_t	size;
	size_t	index;
	void	**ptr;

	size = ft_lstsize(lst);
	ptr = (void **)malloc(sizeof(void *) * size);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (lst != NULL && index < size)
	{
		ptr[index] = lst->content;
		lst = lst->next;
		index++;
	}
	*ret_size = index;
	return (ptr);
}
