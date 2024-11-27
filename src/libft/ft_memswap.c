/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:36:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 17:10:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief swap data valu1 and valu2
 * @param value1 one value
 * @param value2 one value
 * @param size size value1 and value2 [byte]
 * @return none
 */
void	ft_memswap(void *value1, void *value2, size_t size)
{
	size_t			index;
	unsigned char	*v1;
	unsigned char	*v2;
	unsigned char	temp;

	v1 = (unsigned char *)value1;
	v2 = (unsigned char *)value2;
	index = 0;
	while (index < size)
	{
		temp = v1[index];
		v1[index] = v2[index];
		v2[index] = temp;
		index++;
	}
	return ;
}
