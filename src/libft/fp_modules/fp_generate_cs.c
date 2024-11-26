/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_generate_cs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:14:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:14:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include "fp_module_int_defs.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static void	read_flag(t_cs *cs, const char **format);
static void	read_min_field_width(t_cs *cs, const char **format);
static void	read_precision(t_cs *cs, const char **format);
static void	read_cs(t_cs *cs, const char **fmt);

/**
 * get conversion specification.
 * @param format conversion format
 * @return
 */
t_cs	*fp_generate_cs(const char *format)
{
	t_cs	*cs;

	if (*format++ != '%')
		return (NULL);
	cs = fp_new_t_cs();
	if (cs == NULL)
		return (NULL);
	read_flag (cs, &format);
	read_min_field_width(cs, &format);
	read_precision(cs, &format);
	read_cs(cs, &format);
	if (cs->type == '\0' || errno == ERANGE)
	{
		fp_destroy_t_cs(cs);
		return (NULL);
	}
	fp_rewrite_special_behavior(cs);
	return (cs);
}

static void	read_flag(t_cs *cs, const char **format)
{
	char	flag;

	while (ft_includes(**format, FP_FLAGS))
	{
		flag = **format;
		if (flag == '#')
			cs->flag_sharp = true;
		else if (flag == '0')
			cs->flag_zero = true;
		else if (flag == '-')
			cs->flag_minus = true;
		else if (flag == ' ')
			cs->flag_space = true;
		else if (flag == '+')
			cs->flag_plus = true;
		*format += 1;
	}
	return ;
}

static void	read_min_field_width(t_cs *cs, const char **format)
{
	if (! ft_isdigit(**format))
		return ;
	cs->is_set_field_width = true;
	cs->field_width = ft_strtol(*format, (char **)format, 10);
	return ;
}

static void	read_precision(t_cs *cs, const char **format)
{
	if (**format != '.')
		return ;
	*format += 1;
	cs->is_set_precision = true;
	cs->precision = ft_strtol(*format, (char **)format, 10);
	if (cs->precision < 0)
	{
		cs->precision = 0;
		cs->is_set_precision = false;
	}
	return ;
}

static void	read_cs(t_cs *cs, const char **fmt)
{
	if (ft_includes(**fmt, FP_CONVERSION_TYPES))
		cs->type = **fmt;
	else
		cs->type = '\0';
	return ;
}
