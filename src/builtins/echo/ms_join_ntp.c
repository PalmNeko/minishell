/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_join_ntp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:53:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/16 01:53:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_int_echo.h"
#include <stddef.h>

char	*ms_join_ntp(char *const ntp[], const char *pad)
{
	size_t	total_len;
	size_t	index;
	char	*joined;

	total_len = 0;
	index = 0;
	while (ntp[index] != NULL)
		total_len += ft_strlen(ntp[index++]);
	if (index >= 2)
		total_len += ft_strlen(pad) * (index - 1);
	joined = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (joined == NULL)
		return (NULL);
	index = 0;
	while (ntp[index] != NULL)
	{
		if (index != 0)
			ft_strncat(joined, pad, total_len);
		ft_strncat(joined, ntp[index], total_len);
		index++;
	}
	return (joined);
}
