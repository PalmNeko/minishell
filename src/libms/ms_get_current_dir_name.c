/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_current_dir_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:53:56 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/01 08:19:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static char	*__ms_get_current_dir_name(void);

/**
 * see get_current_dir_name(3).
 */
char	*ms_get_current_dir_name(void)
{
	char		*cwd;
	struct stat	cwd_statbuf;
	struct stat	pwd_statbuf;

	cwd = __ms_get_current_dir_name();
	if (ms_getenv("PWD") == NULL)
		return (cwd);
	if (stat(cwd, &cwd_statbuf) == -1
		|| stat(ms_getenv("PWD"), &pwd_statbuf) == -1)
		return (cwd);
	if (ft_memcmp(&cwd_statbuf, &pwd_statbuf, sizeof(struct stat)) == 0)
	{
		free(cwd);
		return (ft_strdup(ms_getenv("PWD")));
	}
	return (cwd);
}

static char	*__ms_get_current_dir_name(void)
{
	size_t	size;
	char	*buf;
	char	*cwd;

	size = 1024;
	buf = (char *)malloc(size);
	if (buf == NULL)
		return (NULL);
	while (getcwd(buf, size) == NULL)
	{
		free(buf);
		if (errno != ERANGE)
			return (NULL);
		if (size == SIZE_MAX)
			return (NULL);
		else if (size > SIZE_MAX / 2)
			size *= 2;
		else
			size = SIZE_MAX;
		buf = (char *)malloc(size);
		if (buf == NULL)
			return (NULL);
	}
	cwd = ft_strdup(buf);
	return (free(buf), cwd);
}
