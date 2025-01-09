/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_to_upper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:49:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 16:18:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

char	*fp_to_upper(bool be_upper, int *len, char *str)
{
	(void)len;
	if (str == NULL)
		return (NULL);
	if (be_upper == true)
		return (ft_strtoupper(str));
	else
		return (str);
}
