/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:07 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:33:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && len < maxlen)
		len++;
	return (len);
}
