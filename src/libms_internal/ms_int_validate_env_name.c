/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_int_validate_env_name.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:01:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 13:49:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

bool	ms_int_validate_env_name(const char *name)
{
	if (name == NULL)
		return (false);
	else if (ft_strchr(name, '=') != NULL)
		return (false);
	else if (ft_strlen(name) == 0)
		return (false);
	else
		return (true);
}
