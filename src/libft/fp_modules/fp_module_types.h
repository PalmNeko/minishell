/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_module_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:06:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:12:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_MODULE_TYPES_H
# define FP_MODULE_TYPES_H

# include <stdbool.h>

/** conversion specifier
 * @param conversion_specifier conversion specifier
 * @param flag_shape # flag
 * @param flag_minus - flag
 * @param flag_plus + flag
 * @param flag_zero 0 flag
 * @param flag_space ` ` flag
 * @param is_set_field_width is set specified minimum field width
 * @param field_width specified minimum field width value.
 * @param is_set_precision is set precision
 * @param precision precision
 */
typedef struct s_conv_specification
{
	char	type;
	bool	flag_sharp;
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_zero;
	bool	flag_space;
	bool	is_set_field_width;
	int		field_width;
	bool	is_set_precision;
	int		precision;
}	t_cs;

#endif
