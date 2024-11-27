/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:41:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:42:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	length;

	copy = NULL;
	length = ft_strlen(s1);
	if (length > n)
		length = n;
	if (length < SIZE_MAX)
		copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, length + 1);
	return (copy);
}
