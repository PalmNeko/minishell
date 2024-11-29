/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_create_string_from_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:23:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:49:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

char	*ms_create_string_from_map(const bool map[256])
{
	size_t	index;
	size_t	str_idx;
	char	str[257];

	index = 0;
	str_idx = 0;
	while (index < 256)
	{
		if (map[index] == true)
			str[str_idx++] = index;
		index++;
	}
	str[str_idx] = '\0';
	return (ft_strdup(str));
}
