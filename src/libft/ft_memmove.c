/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:12:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 16:47:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_p;
	const char	*src_p;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_p = dst;
	src_p = src;
	if (dst_p < src_p)
		return (ft_memcpy(dst_p, src_p, len));
	while (len > 0)
	{
		dst_p[len - 1] = src_p[len - 1];
		len--;
	}
	return (dst);
}
