/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:54:43 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/07 05:29:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include "libms.h"
#include <stddef.h>

static char	*ms_cat_env_var_string(const char *name, const char *value);
static char	**ms_create_environs(char **names);

/**
 * export environ variable
 * @return null terminated string following line format.
 * line format: name=[value]
 * @exception
 * ENOMEM: has no memory
 */
char	**ms_export_env(void)
{
	char	**names;
	char	**exports;

	names = ms_export_names();
	if (names == NULL)
		return (NULL);
	exports = ms_create_environs(names);
	ms_destroy_ntp(names);
	return (exports);
}

static char	**ms_create_environs(char **names)
{
	size_t	envp_len;
	size_t	index;
	size_t	env_index;
	char	**exports;
	char	*value;

	envp_len = ms_ntpsize((void **)names);
	exports = (char **)ft_calloc(envp_len + 1, sizeof(char *));
	if (exports == NULL)
		return (NULL);
	index = 0;
	env_index = 0;
	while (names[index] != NULL)
	{
		value = ms_getenv(names[index]);
		if (value != NULL)
		{
			exports[env_index] = ms_cat_env_var_string(names[index], value);
			if (exports[env_index] == NULL)
				return (ms_destroy_ntp(exports), NULL);
			env_index++;
		}
		index++;
	}
	return (exports);
}

static char	*ms_cat_env_var_string(const char *name, const char *value)
{
	size_t	str_size;
	size_t	offset;
	char	*env_var_string;

	str_size = ft_strlen(name) + ft_strlen("=") + ft_strlen(value) + 1;
	env_var_string = (char *)ft_calloc(str_size, sizeof(char));
	if (env_var_string == NULL)
		return (NULL);
	offset = 0;
	offset += ft_strlcat(env_var_string + offset, name, str_size - offset);
	offset += ft_strlcat(env_var_string + offset, "=", str_size - offset);
	offset += ft_strlcat(env_var_string + offset, value, str_size - offset);
	return (env_var_string);
}
