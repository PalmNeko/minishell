/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:04:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/27 08:10:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static int	ms_export_set_variable(const char *arg);
static int	ms_export_variable(const char *arg);
static int	ms_export_append_variable(const char *arg);
static int	ms_export_error_not_a_valid_identifier(const char *arg);

/**
 * @brief Export variables.
 */
int	ms_export_variables(const char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		ms_export_variable(args[i]);
		i++;
	}
	return (0);
}

static int	ms_export_variable(const char *arg)
{
	char	*name_end;

	name_end = ft_strchr(arg, '=');
	if (name_end == NULL)
		return (1);
	if (name_end == NULL || arg == name_end)
		return (ms_export_error_not_a_valid_identifier(arg), 1);
	if (name_end[-1] == '+')
		return (ms_export_append_variable(arg));
	else
		return (ms_export_set_variable(arg));
}

static int	ms_export_set_variable(const char *arg)
{
	char	*dupped_arg;
	char	*equal_ptr;

	dupped_arg = ft_strdup(arg);
	if (dupped_arg == NULL)
		return (-1);
	equal_ptr = ft_strchr(dupped_arg, '=');
	if (equal_ptr != NULL)
	{
		*equal_ptr = '\0';
		if (ms_setenv(dupped_arg, equal_ptr + 1, 1) == -1)
		{
			free(dupped_arg);
			return (-1);
		}
	}
	ms_add_export(dupped_arg);
	free(dupped_arg);
	return (0);
}

static int	ms_export_append_variable(const char *arg)
{
	char	*name;
	char	*value;
	char	*name_end;

	name_end = ms_strstr(arg, "+=");
	if (name_end == NULL)
		return (1);
	name = ft_strndup(arg, name_end - arg);
	if (name == NULL)
		return (1);
	if (ms_add_export(name) == -1)
		return (free(name), 1);
	if (ms_getenv(name) == NULL)
		value = ft_strdup("");
	else
		value = ft_strdup(ms_getenv(name));
	if (value == NULL)
		return (free(name), 1);
	if (ms_replace_joined_str(&value, name_end + 2) == NULL)
		return (free(name), free(value), 1);
	ms_setenv(name, value, 1);
	return (free(name), free(value), 0);
}

static int	ms_export_error_not_a_valid_identifier(const char *arg)
{
	char	*error_txt;

	error_txt = ft_strdup("`");
	if (error_txt == NULL)
		return (1);
	if (ms_replace_joined_str(&error_txt, arg) == NULL
		|| ms_replace_joined_str(&error_txt, "'") == NULL
		|| ms_replace_joined_str(
			&error_txt, ": not a valid identifier") == NULL)
		return (free(error_txt), 1);
	return (ms_perror_cmd("export", error_txt), free(error_txt), 1);
}
