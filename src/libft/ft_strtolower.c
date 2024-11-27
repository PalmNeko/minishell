/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/04 14:44:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief replace an upper case to a lower case.
 * @param str replacement target strings.
 * @return `str`' string first pointer.
 */
char	*ft_strtolower(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
	return (str);
}
