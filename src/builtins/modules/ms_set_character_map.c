/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_character_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:22:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:35:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ms_set_character_map(const char *str, bool map[256])
{
	while (*str != '\0')
	{
		map[(int)*str] = true;
		str++;
	}
}
