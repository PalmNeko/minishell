/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:18:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 15:18:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (result);
}
