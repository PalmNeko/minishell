/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_isadir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:22:47 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/25 09:37:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

bool	ms_isadir(const char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (false);
	if (S_ISDIR(buf.st_mode))
		return (true);
	return (true);
}
