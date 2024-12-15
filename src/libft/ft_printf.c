/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:08:49 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/30 14:27:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, format);
	print_len = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (print_len);
}
