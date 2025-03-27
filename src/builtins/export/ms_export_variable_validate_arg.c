/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_variable_validate_arg.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:43:26 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/27 11:04:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	ms_export_variable_validate_name(const char *name);

bool	ms_export_variable_validate_arg(const char *arg)
{
	char	*name_end;
	char	*name;
	bool	ret;

	name_end = ft_strchr(arg, '=');
	if (name_end == NULL && name_end - arg >= 1 && name_end[-1] == '+')
		name_end--;
	else
		name_end = ft_strchr(arg, '\0');
	if (name_end == NULL || arg == name_end || ft_isdigit(arg[0]))
		return (false);
	name = ft_strndup(arg, name_end - arg);
	if (name == NULL)
		return (false);
	ret = ms_export_variable_validate_name(name);
	free(name);
	return (ret);
}

static bool	ms_export_variable_validate_name(const char *name)
{
	char	*ptr;

	if (name == NULL || name[0] == '\0' || ft_isdigit(name[0]))
		return (false);
	ptr = (char *)name;
	while (*ptr != '\0')
	{
		if (!ft_isalnum(*ptr) && *ptr != '_')
			return (false);
		ptr++;
	}
	return (true);
}
