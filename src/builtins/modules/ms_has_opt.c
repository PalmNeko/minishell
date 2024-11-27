/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_has_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:51:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/16 01:51:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_has_opt(char *const argv[], const char *opt)
{
	while (*argv != NULL)
	{
		if (ft_strcmp(*argv, opt) == 0)
			return (true);
		argv++;
	}
	return (false);
}
