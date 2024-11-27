/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:52:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 15:38:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief writes len bytes of value c to the string b.
 * @param b - written string memory.
 * @param c - set value.(converted to unsigned char)
 * @param len - set length (size)
 * @return argument `b`
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bp;
	unsigned char	value;
	size_t			set_count;

	bp = b;
	value = c;
	set_count = 0;
	while (set_count < len)
	{
		bp[set_count] = value;
		set_count++;
	}
	return (b);
}
