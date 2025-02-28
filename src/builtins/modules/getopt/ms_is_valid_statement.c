/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_valid_statement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:17:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:51:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ms_is_valid_statement(const char *arg, const char *optstring)
{
	if (arg[0] != '-')
		return (false);
	arg++;
	while (*arg != '\0')
	{
		if (! ft_includes(*arg, (char *)optstring))
			return (false);
		arg++;
	}
	return (true);
}
