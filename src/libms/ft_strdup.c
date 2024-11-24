/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:26:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 22:26:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include <stdlib.h>
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
