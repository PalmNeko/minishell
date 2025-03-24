/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:20:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include <stddef.h>
#include <errno.h>
#include <string.h>

int	ms_get_cd_path(const char *arg_path, char **cd_path)
{
	char	*target_pathname;

	target_pathname = NULL;
	*cd_path = NULL;
	if (arg_path == NULL)
	{
		target_pathname = ms_getenv("HOME");
		if (target_pathname == NULL)
			return (ms_perror_cmd("cd", "HOME not set"), 1);
	}
	else if (ft_strcmp(arg_path, "-") == 0)
	{
		target_pathname = ms_getenv("OLDPWD");
		if (target_pathname == NULL)
			return (ms_perror_cmd("cd", "OLDPWD not set"), 1);
	}
	else
		target_pathname = (char *)arg_path;
	*cd_path = ft_strdup(target_pathname);
	if (*cd_path == NULL)
		return (-1);
	return (0);
}
