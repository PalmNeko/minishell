/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:10:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/11 16:50:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	count;
	char	*joined;

	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(sizeof(char) * count);
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, s1, count);
	ft_strlcat(joined, s2, count);
	return (joined);
}
