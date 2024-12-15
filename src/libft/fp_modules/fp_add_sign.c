/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:14:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "fp_module_int_defs.h"

/**
 * @param type
 * 	0: none add,
 * 	1: add + to positive value,
 * 	2 add ' ' to positive value.
 * @param len length of str. overwrite length of new str.
 * @param str string. maybe free.
 */
char	*fp_add_sign(int type, int *len, char *str)
{
	char	*joined;
	char	*add_sign;

	if (str == NULL)
		return (NULL);
	if (type == FP_SDEFAULT || str[0] == '-')
		return (ft_strdup(str));
	if (type == FP_SSIGN)
		add_sign = "+";
	else if (type == FP_SSPACE)
		add_sign = " ";
	else
		add_sign = "";
	joined = ft_strjoin(add_sign, str);
	if (joined == NULL)
		return (NULL);
	*len += 1;
	return (joined);
}
