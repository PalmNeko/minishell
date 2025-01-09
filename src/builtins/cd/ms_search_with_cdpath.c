/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_search_with_cdpath.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:22:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "cd_internal.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char	*ms_search_with_cdpath(const char *path)
{
	char	**splitted;
	char	**itr;
	char	*chk_path;

	if (ms_is_use_cdpath(path) == false)
		return (NULL);
	splitted = ms_separate(ms_getenv("CDPATH"), ':');
	if (splitted == NULL)
		return (NULL);
	itr = splitted;
	while (*itr != NULL)
	{
		chk_path = ms_path_join(*itr, path);
		if (chk_path == NULL)
			return (ms_destroy_ntp(splitted), NULL);
		if (access(chk_path, F_OK) == 0 && ms_is_dir(chk_path))
			return (ms_destroy_ntp(splitted), chk_path);
		free(chk_path);
		itr++;
	}
	ms_destroy_ntp(splitted);
	return (NULL);
}
