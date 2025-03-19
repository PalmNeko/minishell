/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_restore_environ_memento.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:18:49 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 20:19:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memento.h"
#include <unistd.h>

int	ms_restore_environ_memento(t_environ_memento *memento)
{
	if (dup2(memento->stdin_fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(memento->stdout_fd, STDOUT_FILENO) == -1)
		return (-1);
	if (dup2(memento->stderr_fd, STDERR_FILENO) == -1)
		return (-1);
	return (0);
}
