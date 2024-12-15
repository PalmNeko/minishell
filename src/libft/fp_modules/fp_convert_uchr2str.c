/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_convert_uchr2str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:16:07 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 13:36:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_convert_uchr2str(int *size, unsigned char chr)
{
	char	new_str[2];

	new_str[0] = chr;
	new_str[1] = '\0';
	*size = 1;
	return (ft_strdup(new_str));
}
