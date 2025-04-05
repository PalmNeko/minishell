/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_memento_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:12:52 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/05 02:16:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memento_type.h"
#include <stdlib.h>
#include <unistd.h>

void	ms_memento_destroy(t_environ_memento *memento)
{
	close(memento->stdin_fd);
	close(memento->stdout_fd);
	close(memento->stderr_fd);
	free(memento);
}
