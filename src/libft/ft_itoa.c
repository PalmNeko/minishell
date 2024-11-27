/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:56:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:01:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_itoa(int n)
{
	char		num_str[15];
	const char	*base_chr = "0123456789";
	const int	base = 10;
	int			sign;
	size_t		index;

	sign = 0;
	if (n < 0)
		sign = -1;
	index = 0;
	if (n == 0)
		num_str[index++] = '0';
	while (n != 0)
	{
		num_str[index++] = base_chr[ft_abs(n % base)];
		n /= base;
	}
	if (sign == -1)
		num_str[index++] = '-';
	num_str[index] = '\0';
	ft_strrev(num_str);
	return (ft_strdup(num_str));
}
