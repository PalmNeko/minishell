/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_convert_int2str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:12:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:13:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fp_module.h"

char	*fp_convert_int2str(int precision, int *len, int value)
{
	char	*numstr;
	char	*pad_num;

	*len = 0;
	if (precision == 0 && value == 0)
		return (ft_strdup(""));
	numstr = ft_itoa(value);
	if (numstr == NULL)
		return (NULL);
	*len = ft_strlen(numstr);
	if (numstr[0] == '-')
		pad_num = fp_pad_for_num(precision + 1, len, numstr);
	else
		pad_num = fp_pad_for_num(precision, len, numstr);
	free(numstr);
	return (pad_num);
}
