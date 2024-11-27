/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:29:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/04 14:45:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief replace a lower case to an upper case.
 * @param str replacement target strings.
 * @return `str`' string first pointer.
 */
char	*ft_strtoupper(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}
