/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:11:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:14:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "fp_module.h"
#include "libft.h"

char	*fp_gen_str(t_cs *cs, int *len, char *str)
{
	size_t	size;
	char	*tmp;

	if (str == NULL && cs->is_set_precision && cs->precision < 6)
			str = ft_strdup("");
	else if (str == NULL)
			str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	if (cs->is_set_precision == true)
	{
		tmp = fp_cut_string(cs->precision, len, str);
		free(str);
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	size = ft_strnlen(str, (size_t)INT_MAX + 1);
	if (size > INT_MAX)
		return (free(str), NULL);
	*len = size;
	return (str);
}
