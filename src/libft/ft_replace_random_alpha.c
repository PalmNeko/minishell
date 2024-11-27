/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_random_alpha.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:43:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/02 16:49:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

char	*ft_replace_random_alpha(
			char *str, int cnt, uint32_t seed, uint32_t no)
{
	int			index;
	uint32_t	random;

	index = 0;
	while (str[index] != '\0' && index < cnt)
	{
		random = ft_xorshift_u32(seed, no + index) % 52;
		if (random < 26)
			str[index] = 'a' + random;
		else
			str[index] = 'A' + random - 26;
		index++;
	}
	return (str);
}
