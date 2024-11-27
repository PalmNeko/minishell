/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:42:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/04 15:45:46 by tookuyam         ###   ########.fr       */
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
bool	ft_includes(char c, char *sets)
{
	size_t		index;

	index = 0;
	while (sets[index] != '\0')
	{
		if (sets[index] == c)
			return (true);
		index++;
	}
	return (false);
}
