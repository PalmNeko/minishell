/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:20:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:33:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			malloc_size;

	if (size > 0 && count > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	malloc_size = count * size;
	ptr = (unsigned char *)malloc(sizeof(unsigned char) * malloc_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, malloc_size);
	return (ptr);
}
