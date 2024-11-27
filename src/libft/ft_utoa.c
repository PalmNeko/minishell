/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:56:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:27:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_utoa(unsigned int n)
{
	char		num_str[15];
	const char	*base_chr = "0123456789";
	const int	base = 10;
	size_t		index;

	index = 0;
	if (n == 0)
		num_str[index++] = '0';
	while (n != 0)
	{
		num_str[index++] = base_chr[ft_abs(n % base)];
		n /= base;
	}
	num_str[index] = '\0';
	ft_strrev(num_str);
	return (ft_strdup(num_str));
}
