/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:57:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:42:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

/**
 * see strpbrk(3)
 */
char	*ms_strpbrk(const char *s, const char *accept)
{
	bool	accept_set[256];

	ft_memset(accept_set, false, sizeof(accept_set));
	while (*accept != '\0')
	{
		accept_set[(int)*accept] = true;
		accept++;
	}
	while (*s != '\0')
	{
		if (accept_set[(int)*s] == true)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
