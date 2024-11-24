/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:58:49 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/16 01:58:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;
	size_t				index;

	dest_p = dest;
	src_p = src;
	index = 0;
	while (index < n)
	{
		dest_p[index] = src_p[index];
		index++;
	}
	return (dest);
}
