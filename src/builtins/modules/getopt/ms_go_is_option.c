/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_go_is_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:10:27 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 12:29:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ms_go_is_option(const char *arg)
{
	if (ft_strcmp(arg, "--") == 0)
		return (false);
	else if (arg[0] == '-' && arg[1] != '\0')
		return (true);
	else
		return (false);
}
