/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:59:47 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 16:06:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		index;
	const char	cmp_c = c;

	index = ft_strlen(s);
	while (index > 0)
	{
		if (s[index] == cmp_c)
			return ((char *)(s + index));
		index--;
	}
	if (s[index] == cmp_c)
		return ((char *)(s + index));
	return (NULL);
}
