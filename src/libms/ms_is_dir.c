/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:56:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/06 15:56:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * check if the path is directory.
 * following symlinks if the path is symlink.
 * @param path path to be checked
 * @return true if the path is directory. false if not.
 */
bool	ms_is_dir(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (false);
	if (statbuf.st_mode & S_IFDIR)
		return (true);
	else
		return (false);
}
