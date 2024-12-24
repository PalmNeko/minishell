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

char	*ms_get_cd_path(const char *arg_path)
{
	char *target_pathname;

	target_pathname = NULL;
	if (arg_path == NULL)
	{
		target_pathname = ms_getenv("HOME");
		if (target_pathname == NULL)
			ms_perror_cmd("cd", "HOME not set");
	}
	else if (ft_strcmp(arg_path, "-") == 0)
	{
		target_pathname = ms_getenv("OLDPWD");
		if (target_pathname == NULL)
			ms_perror_cmd("cd", "OLDPWD not set");
	}
	else
	{
		target_pathname = ft_strdup(arg_path);
		if (target_pathname == NULL)
			ms_perror_cmd("cd", strerror(errno));
	}
	return (target_pathname);
}
