/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_export_environ.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:19:30 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 05:58:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stdlib.h>

static void	ms_setup_inherit_export(void);
static void	ms_setup_special_export(void);

void	ms_setup_export_environ(void)
{
	ms_setup_inherit_export();
	ms_setup_special_export();
}

static void	ms_setup_inherit_export(void)
{
	int			i;
	int			res;
	char		*name_end;
	char		*name;
	extern char	**environ;

	i = 0;
	while (environ[i] != NULL)
	{
		name_end = ft_strchr(environ[i], '=');
		if (name_end == NULL || name_end == environ[i])
			continue ;
		name = ft_strndup(environ[i], name_end - environ[i]);
		if (name == NULL)
			return ;
		res = ms_add_export(name);
		free(name);
		if (res == -1)
			return ;
		i++;
	}
	return ;
}

static void	ms_setup_special_export(void)
{
	ms_add_export("OLDPWD");
	ms_add_export("PWD");
	ms_add_export("SHLVL");
	ms_remove_export("_");
}
