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
#include <stdio.h>

int	ms_uncapture(int target_fd, int fds[2], int *stored_fd)
{
	dup2(*stored_fd, target_fd);
	close(*stored_fd);
	close(fds[0]);
	close(fds[1]);
	return (0);
}
