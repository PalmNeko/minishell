/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_save_environ_memento.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:15:35 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 20:28:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memento.h"
#include <stdlib.h>
#include <unistd.h>

t_environ_memento	*ms_save_environ_memento(void)
{
	t_environ_memento	*memento;
	t_environ_memento	tmp_memento;

	tmp_memento.stdin_fd = dup(STDIN_FILENO);
	if (tmp_memento.stdin_fd == -1)
		return (NULL);
	tmp_memento.stdout_fd = dup(STDOUT_FILENO);
	if (tmp_memento.stdout_fd == -1)
		return (NULL);
	tmp_memento.stderr_fd = dup(STDERR_FILENO);
	if (tmp_memento.stderr_fd == -1)
		return (NULL);
	memento = (t_environ_memento *)malloc(sizeof(t_environ_memento));
	if (memento == NULL)
		return (NULL);
	*memento = tmp_memento;
	return (memento);
}
