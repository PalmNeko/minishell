/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:26:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 15:22:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief copies n bytes from memory area src to memory area dst.
 * @attention If dst and src overlap, behavior is undefined.
 * Applications in which dst and src might overlap should use memmove(3)
 * instead.
 * @param dst - copied memory
 * @param src - copy source
 * @param n - copy byte size
 * @return original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		copy_count;
	char		*dst_p;
	const char	*src_p;

	if (dst == NULL && src == NULL)
		return (dst);
	dst_p = dst;
	src_p = src;
	copy_count = 0;
	while (copy_count < n)
	{
		dst_p[copy_count] = src_p[copy_count];
		copy_count++;
	}
	return (dst);
}
