/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:18:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:10:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	length;
	size_t	size;

	copy = NULL;
	length = ft_strlen(s1);
	if (length == SIZE_MAX)
		return (NULL);
	size = length + 1;
	copy = (char *)malloc(sizeof(char) * size);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, size);
	return (copy);
}
