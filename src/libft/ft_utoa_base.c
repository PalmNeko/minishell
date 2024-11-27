/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:18:58 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:30:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_utoa_base_str(unsigned int n, const char *base_str)
{
	char		num_str[40];
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
