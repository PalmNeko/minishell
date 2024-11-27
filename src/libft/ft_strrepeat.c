/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:24:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 23:08:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

/**
 * @brief repeat `str` `times` times.
 * @param str repeated string.
 * @param times repeat times.
 * @return repeated string allocated in memory. NULL if an error occurs.
 */
char	*ft_strrepeat(char *str, unsigned int times)
{
	size_t			len;
	unsigned char	cnt;
	char			*repeated_string;

	len = ft_strlen(str);
	if (times > 0 && len > SIZE_MAX / times)
		return (NULL);
	repeated_string = (char *)malloc(sizeof(char) * (len * times + 1));
	if (repeated_string == NULL)
		return (NULL);
	cnt = 0;
	while (cnt < times)
	{
		ft_memcpy(repeated_string + (cnt * len), str, len);
		cnt++;
	}
	repeated_string[times * len] = '\0';
	return (repeated_string);
}
