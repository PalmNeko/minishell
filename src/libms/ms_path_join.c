/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:43:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 15:43:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * join base and path.
 * if base is not end with '/', add '/' before joining.
 * @param base base path
 * @param path joined path
 * @return joined path if success. NULL if failed.
 * @exception
 * ENOMEM: failed to allocate memory
 * @example
 * ms_path_join("/usr", "bin") => "/usr/bin"
 * ms_path_join("/usr/", "/bin") => "/usr//bin"
 */
char	*ms_path_join(const char *base, const char *path)
{
	char	*nptr;
	char	*joined;
	char	*tmp;

	nptr = ft_strrchr(base, '\0');
	if (base[0] != '\0' && nptr[-1] != '/')
	{
		tmp = ft_strjoin(base, "/");
		if (tmp == NULL)
			return (NULL);
		joined = ft_strjoin(tmp, path);
		free(tmp);
		return (joined);
	}
	return (ft_strjoin(base, path));
}
