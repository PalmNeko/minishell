/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:54:57 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 05:50:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms_internal.h"
#include <stdlib.h>
#include <errno.h>

static int	ms_setenv_overwrite(const char *name, const char *value);
static int	ms_setenv_if_unset(const char *name, const char *value);
static int	ms_overwrite_ms_var(
				t_ms_var *ms_var, const char *name, const char *value);
static int	ms_append_new_env(const char *name, const char *value);

/**
 * set environment variable according to `overwrite`.
 * @param name variable name
 * @param value variable value.
 * @param overwrite if overwrite is nonzero; if overwrite is zero, then the
 * value of name  is  not  changed
 * @return zero on success. -1 on error, with errno set.
 * @exception
 * ENOMEM: has no memory.
 * EINVAL: name is NULL, points to a string of length 0, or contains an '='
 * character.
 */
int	ms_setenv(const char *name, const char *value, int overwrite)
{
	if (ms_int_import_on_initial() == -1)
		return (-1);
	if (ms_int_validate_env_name(name) == false)
	{
		errno = EINVAL;
		return (-1);
	}
	if (overwrite == 0)
		return (ms_setenv_if_unset(name, value));
	else
		return (ms_setenv_overwrite(name, value));
}

int	ms_setenv_overwrite(const char *name, const char *value)
{
	t_ms_var	*ms_var;

	ms_var = ms_find_ms_var(name);
	if (ms_var != NULL)
		return (ms_overwrite_ms_var(ms_var, name, value));
	else
		return (ms_append_new_env(name, value));
}

int	ms_setenv_if_unset(const char *name, const char *value)
{
	t_ms_var	*ms_var;

	ms_var = ms_find_ms_var(name);
	if (ms_var != NULL)
		return (0);
	else
		return (ms_append_new_env(name, value));
}

int	ms_overwrite_ms_var(t_ms_var *ms_var, const char *name, const char *value)
{
	char	*new_name;
	char	*new_value;

	new_name = ft_strdup(name);
	if (new_name == NULL)
		return (-1);
	new_value = ft_strdup(value);
	if (new_value == NULL)
		return (-1);
	free(ms_var->name);
	free(ms_var->value);
	ms_var->name = new_name;
	ms_var->value = new_value;
	return (0);
}

static int	ms_append_new_env(const char *name, const char *value)
{
	t_list		**environ_lst;
	t_list		*new_list;
	t_ms_var	*new_ms_var;

	environ_lst = ms_int_get_environ_variable();
	new_ms_var = ms_int_create_ms_var(name, value);
	if (new_ms_var == NULL)
		return (-1);
	new_list = ft_lstnew(new_ms_var);
	if (new_list == NULL)
		return (ms_int_destroy_ms_var(new_ms_var), -1);
	ft_lstadd_back(environ_lst, new_list);
	return (0);
}
