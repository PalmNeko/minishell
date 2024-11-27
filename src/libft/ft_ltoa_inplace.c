/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:08:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/08 17:08:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/**
 * rewrite `buffer` to string `value` by `radix`
 * @param value - source number
 * @param buffer - A buffer large enough to store the number. Hexadecimal
 * numbers use lowercase letters.
 * @param radix - radix for convert : only 8 10 and 16.
 * @attention A buffer flow is possible when the buffer is smaller than 23
 * bytes.ex. radix=8, value=-9223372036854775808
 */
char	*ft_ltoa_inplace(long value, char *buffer, int radix)
{
	const char	*base_chr = "0123456789abcdef";
	int			sign;
	size_t		index;

	if (! (radix == 8 || radix == 10 || radix == 16))
		return (NULL);
	sign = 0;
	if (value < 0)
		sign = -1;
	index = 0;
	if (value == 0)
		buffer[index++] = '0';
	while (value != 0)
	{
		buffer[index++] = base_chr[ft_abs(value % radix)];
		value /= radix;
	}
	if (sign == -1)
		buffer[index++] = '-';
	buffer[index] = '\0';
	ft_strrev(buffer);
	return (buffer);
}
