/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_get_cs_len.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:26:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "fp_module_int_defs.h"
#include "fp_module.h"
#include "libft.h"

/**
 * get length of one conversion specification.
 * @param format conversion specification format. this format needs at start '%'.
 * @return return conversion specification length if of success.
 * negative value if of error.
*/
int	fp_get_cs_len(const char *format)
{
	size_t	index;

	index = 0;
	if (format[index++] != '%')
		return (-1);
	while (ft_includes(format[index], FP_FLAGS))
		index++;
	while (ft_isdigit(format[index]))
		index++;
	if (format[index] == '.')
		index++;
	while (ft_isdigit(format[index]))
		index++;
	if (! ft_includes(format[index++], FP_CONVERSION_TYPES))
		return (-1);
	return (index);
}
