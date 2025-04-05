/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:19:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 14:19:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	ms_is_should_escape(const char *path);

void	ms_perror_cd(const char *path)
{
	char	*escaped_path;
	char	*path_string;

	if (ms_is_should_escape(path) == false)
		ms_perror_cmd2("cd", path, strerror(errno));
	else
	{
		path_string = ft_strdup("$'");
		if (path_string == NULL)
			return ;
		escaped_path = ms_dup_escapedstr(path);
		if (escaped_path != NULL)
		{
			if (ms_replace_joined_str(&path_string, escaped_path) != NULL)
			{
				if (ms_replace_joined_str(&path_string, "'") != NULL)
					ms_perror_cmd2("cd", path_string, strerror(errno));
			}
			free(escaped_path);
		}
		free(path_string);
	}
}

static bool	ms_is_should_escape(const char *path)
{
	while (*path != '\0')
	{
		if (ft_isprint(*path) == 0)
			return (true);
		path++;
	}
	return (false);
}
