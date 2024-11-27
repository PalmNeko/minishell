/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:52:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:13:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include "./fp_modules/fp_module.h"
#include "libft.h"

static int	print_cs(int fd, const char **format, va_list arg_ptr);
static int	print_until_char_fd(int fd, const char **format, char c);

int	ft_vdprintf(int fd, const char *format, va_list arg_ptr)
{
	size_t	len;
	int		tmp_len;

	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			tmp_len = print_cs(fd, &format, arg_ptr);
		else
			tmp_len = print_until_char_fd(fd, &format, '%');
		if (tmp_len < 0)
			return (-1);
		len += tmp_len;
		if (len > INT_MAX)
			return (-1);
	}
	return ((int)len);
}

static int	print_cs(int fd, const char **format, va_list arg_ptr)
{
	t_cs	*cs;
	int		print_len;
	int		specification_len;

	cs = fp_generate_cs(*format);
	if (cs == NULL)
		return (-1);
	print_len = fp_vdprint_cs(fd, cs, arg_ptr);
	fp_destroy_t_cs(cs);
	specification_len = fp_get_cs_len(*format);
	if (specification_len < 0)
		return (-1);
	*format += specification_len;
	return (print_len);
}

static int	print_until_char_fd(int fd, const char **format, char c)
{
	size_t		len;
	const char	*str;

	len = 0;
	str = *format;
	while (str[len] != c && str[len] != '\0' && len <= INT_MAX)
		len++;
	if (len > INT_MAX && str[len] != c && str[len] != '\0')
		return (-1);
	*format += len;
	return ((int)write(fd, str, len));
}
