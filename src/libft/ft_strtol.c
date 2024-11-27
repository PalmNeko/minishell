/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:12:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 19:19:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <errno.h>
#include <limits.h>
#include "libft.h"

static long	_ft_strtol(char **str, int base);
static int	chr_to_value_base(char c);
static int	exchange_base(char **str, int base);
static int	include_base(char chr, int base);

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	ret;
	char	**iter;

	if (str == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	if (endptr != NULL)
	{
		*endptr = (char *)str;
		iter = endptr;
	}
	else
		iter = (char **)&str;
	ret = _ft_strtol(iter, base);
	return (ret);
}

static long	_ft_strtol(char **str, int base)
{
	int			sign_direction;
	int			add_value;
	long		ret;
	char		*start;

	sign_direction = 1;
	start = *str;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
		sign_direction *= -1;
	if (**str == '+' || **str == '-')
		(*str)++;
	base = exchange_base(str, base);
	if (! include_base(**str, base))
		*str = start;
	ret = 0;
	while (include_base(**str, base))
	{
		add_value = sign_direction * chr_to_value_base(**str);
		ret = ft_mul_l(ret, base);
		ret = ft_add_l(ret, add_value);
		(*str)++;
	}
	return (ret);
}

static int	chr_to_value_base(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0);
}

static int	exchange_base(char **str, int base)
{
	if (base != 0)
		return (base);
	if ('1' <= **str && **str <= '9')
		return (10);
	else if (ft_strncmp(*str, "0x", 2) == 0)
	{
		*str += 2;
		return (16);
	}
	else if (*str[0] == '0')
	{
		*str += 1;
		return (8);
	}
	return (-1);
}

static int	include_base(char chr, int base)
{
	const char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	const char	*base_str_upper = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			index;

	index = 0;
	while (index < base)
	{
		if (base_str[index] == chr || base_str_upper[index] == chr)
			return (!0);
		index++;
	}
	return (0);
}
