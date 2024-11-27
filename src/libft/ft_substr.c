/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:42:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/11 18:04:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Cuts `length` from the `start`th string of the string `s`.
 * @param s - target string.
 * @param start - start index.
 * @param len - The length of the character to be cut.
 * @return Allocated cutted string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	index = ft_strnlen(s, start);
	s += index;
	len = ft_strnlen(s, len);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}
