/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:42:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:23:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	index;
	char			*mapped;

	len = ft_strlen(s);
	if (len >= UINT_MAX)
		return (NULL);
	mapped = (char *)malloc(sizeof(char) * (len + 1));
	if (mapped == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		mapped[index] = f(index, s[index]);
		index++;
	}
	mapped[index] = '\0';
	return (mapped);
}
