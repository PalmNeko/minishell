/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:14:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/10 15:48:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	char_count;
	size_t	length;

	length = ft_strlen(src);
	if (length == 0 && dstsize == 0)
		return (0);
	char_count = 0;
	while (src[char_count] != '\0' && char_count + 1 < dstsize)
	{
		dst[char_count] = src[char_count];
		char_count++;
	}
	if (dstsize > 0)
		dst[char_count] = '\0';
	return (length);
}
