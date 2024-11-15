/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_capture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:47:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/15 22:47:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ms_capture(int target_fd, int fds[2], int *stored_fd)
{
	*stored_fd = dup(target_fd);
	if (*stored_fd == -1)
		return (-1);
	if (pipe(fds) == -1)
	{
		close(*stored_fd);
		return (-1);
	}
	int flags;

	flags = fcntl(fds[0], F_GETFL);
	flags |= O_NONBLOCK;
	fcntl(fds[0], F_SETFL, flags);
	if (dup2(fds[1], target_fd) == -1)
	{
		close(*stored_fd);
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	return (fds[0]);
}
