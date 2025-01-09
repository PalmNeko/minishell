/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strincludes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:00:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/04 14:22:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

/**
 * @brief search sets characters from texts.
 * @param texts search texts.
 * @param sets search characters.
 * @return true if found. false if not found.
 */
bool	ft_strincludes(char *texts, char *sets)
{
	bool	check_map[256];
	int		index;

	index = 0;
	ft_memset(check_map, false, 256);
	while (sets[index] != '\0')
	{
		check_map[(unsigned char)sets[index]] = true;
		index++;
	}
	index = 0;
	while (texts[index] != '\0')
	{
		if (check_map[(unsigned char)texts[index]] == true)
			return (true);
		index++;
	}
	return (false);
}
