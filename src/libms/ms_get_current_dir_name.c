/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_current_dir_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:53:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/30 17:13:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

/**
 * see get_current_dir_name(3). But this function don't use PWD variable.
 */
char	*ms_get_current_dir_name(void)
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
