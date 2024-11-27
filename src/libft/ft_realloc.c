/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:15:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 17:35:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	void	*new_ptr;
	size_t	cpy_size;

	new_ptr = (void *)malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	cpy_size = 0;
	if (old_size < size)
		cpy_size = old_size;
	else
		cpy_size = size;
	ft_memcpy(new_ptr, ptr, cpy_size);
	return (new_ptr);
}
