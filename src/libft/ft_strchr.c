/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:36:42 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/10 15:38:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const char	cmp_c = c;

	while (*s != '\0')
	{
		if (*s == cmp_c)
			return ((char *)s);
		s++;
	}
	if (*s == cmp_c)
		return ((char *)s);
	return (NULL);
}
