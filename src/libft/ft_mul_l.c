/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:41:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 12:58:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

long	ft_mul_l(long value, long mul_value)
{
	long	min;
	long	max;

	if (value == 0 || mul_value == 0)
		return (0);
	min = ft_ifl(value < mul_value, value, mul_value);
	max = ft_ifl(value > mul_value, value, mul_value);
	if ((max < 0) || (min > 0))
	{
		if (min > 0 && min > LONG_MAX / max)
			return (ft_set_errno(ERANGE), LONG_MAX);
		else if (min < 0 && min < LONG_MAX / max)
			return (ft_set_errno(ERANGE), LONG_MAX);
	}
	else
	{
		if (min < LONG_MIN / max)
			return (ft_set_errno(ERANGE), LONG_MIN);
	}
	return (value * mul_value);
}
