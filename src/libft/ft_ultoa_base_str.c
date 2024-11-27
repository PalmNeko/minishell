/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 18:16:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief value `n` to string for unsigned long value by `base_str`.
 * @param n - target value for unsigned long.
 * @param base_str - base str. If this is "0123456789abcdef", it mean hex.
 * Also, "0123456789" is decimal.
 * @return Allocated converted string.
 */
char	*ft_ultoa_base_str(unsigned long n, const char *base_str)
{
	char		num_str[70];
	int			base;
	size_t		index;

	base = ft_strlen(base_str);
	index = 0;
	if (n == 0)
		num_str[index++] = '0';
	while (n != 0)
	{
		num_str[index++] = base_str[ft_abs(n % base)];
		n /= base;
	}
	num_str[index] = '\0';
	ft_strrev(num_str);
	return (ft_strdup(num_str));
}
