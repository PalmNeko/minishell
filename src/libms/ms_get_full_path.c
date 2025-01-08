/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_full_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:24:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 14:24:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"

char	*ms_get_full_path(const char *basedir, const char *path)
{
	char	*abs_path;

	if (path[0] == '/')
		return (ft_strdup(path));
	abs_path = ms_path_join(basedir, path);
	return (abs_path);
}
