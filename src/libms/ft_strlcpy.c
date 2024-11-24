/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:28:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 22:28:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
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
