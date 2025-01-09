/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:17:52 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:24:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	chk_len;
	size_t	haystack_len;
	size_t	needle_len;
	int		comp_result;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (haystack_len < needle_len)
		return (NULL);
	if (needle_len == 0)
		return ((char *)haystack);
	chk_len = 0;
	while (*haystack != '\0'
		&& chk_len + needle_len <= len
		&& chk_len + needle_len <= haystack_len)
	{
		comp_result = ft_strncmp(needle, haystack, needle_len);
		if (comp_result == 0)
			return ((char *)haystack);
		haystack++;
		chk_len++;
	}
	return (NULL);
}
