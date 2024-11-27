/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_uintstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:08:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 16:58:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include <stddef.h>
#include <stdlib.h>

char	*fp_gen_uintstr(t_cs *cs, int *len, unsigned long value, int base)
{
	char	*str;
	char	*tmp;
	int		zero_field_width;

	zero_field_width = 0;
	if (cs->flag_zero && cs->is_set_field_width)
		zero_field_width = cs->field_width;
	tmp = fp_convert_uint2str(cs->precision, len, value, base);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = fp_pad_for_num(zero_field_width, len, str);
	free(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = fp_add_0x(cs->flag_sharp, len, str);
	free(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	fp_to_upper(cs->type == 'X', len, str);
	return (str);
}
