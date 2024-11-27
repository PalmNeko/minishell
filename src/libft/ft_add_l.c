/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:42:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 18:42:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>

long	ft_add_l(long value, long add_value)
{
	if (add_value > 0 && value > LONG_MAX - add_value)
	{
		errno = ERANGE;
		return (LONG_MAX);
	}
	else if (add_value < 0 && value < LONG_MIN - add_value)
	{
		errno = ERANGE;
		return (LONG_MIN);
	}
	return (value + add_value);
}
