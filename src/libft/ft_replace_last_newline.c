/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_last_newline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:43:49 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 11:43:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

bool	ft_replace_last_newline(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (false);
	if (str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
		return (true);
	}
	return (false);
}
