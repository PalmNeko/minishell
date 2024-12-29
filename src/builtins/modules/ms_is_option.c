/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/29 16:53:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_is_option(const char *arg)
{
	if (arg == NULL)
		return (false);
	else if (ft_strcmp(arg, "--") == 0)
		return (false);
	else if (arg[0] == '-' && arg[1] != '\0')
		return (true);
	else
		return (false);
}
