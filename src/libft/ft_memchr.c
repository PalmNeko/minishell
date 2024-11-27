/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:35:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 13:48:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief locates the first occurrence of `c` in string `s`.
 * @param s - searched string.
 * @param c - searching character. (converted to an unsigned char)
 * @param n - size of `s` parameter. (unit: byte)
 * @return A pointer to the byte located.
 * @return Or NULL if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sp;
	unsigned char	value;
	size_t			index;

	sp = (unsigned char *)s;
	value = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (sp[index] == value)
			return (sp + index);
		index++;
	}
	return (NULL);
}
