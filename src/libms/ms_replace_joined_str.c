/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_replace_joined_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:17:18 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/14 17:17:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief replace left string with joined string.
 * @param left left string.
 * @param right right string.
 * @return replaced string.
 */
char	*ms_replace_joined_str(char **left, char *right)
{
	char	*tmp;

	tmp = ft_strjoin(*left, right);
	if (tmp == NULL)
		return (NULL);
	free(*left);
	*left = tmp;
	return (*left);
}
