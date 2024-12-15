/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:51:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 15:04:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 * @param s1 - casted unsigned char
 * @param s2 - casted unsigned char
 * @param n - s1 and s2 bytes
 * @return Returns zero if the two strings are identical.
 * Returns the difference between the first two differing bytes.
 * Zero-length strings are always identical.
 * @attention `Zero-length strings are always identical.` is not required by
 * C and portable code should only depend on the sign of the returned value.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1p;
	const unsigned char	*s2p;
	size_t				count;

	s1p = s1;
	s2p = s2;
	count = 0;
	while (count < n)
	{
		if (s1p[count] != s2p[count])
			return ((s1p[count] - s2p[count]));
		count++;
	}
	return (0);
}
