/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_cut_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:12:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 14:55:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*fp_cut_string(int length, int *size, char *str)
{
	char	*new_str;

	if (str == NULL)
		return (NULL);
	if (length < *size)
		*size = length;
	new_str = ft_strndup(str, length);
	return (new_str);
}
