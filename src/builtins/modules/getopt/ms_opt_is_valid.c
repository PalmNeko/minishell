/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_opt_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:09:44 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:51:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ms_opt_is_valid(int opt, const char *optstring)
{
	if (ft_includes(opt, (char *)optstring))
		return (true);
	return (false);
}
