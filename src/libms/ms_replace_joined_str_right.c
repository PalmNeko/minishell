/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_replace_joined_str_right.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:23:44 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/14 04:25:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief replace right string with joined string.
 * @param left left string.
 * @param right right string.
 * @return replaced string.
 */
char	*ms_replace_joined_str_right(const char *left, char **right)
{
	char	*tmp;

	tmp = ft_strjoin(left, *right);
	if (tmp == NULL)
		return (NULL);
	free(*right);
	*right = tmp;
	return (*right);
}
