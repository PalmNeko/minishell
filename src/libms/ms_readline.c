/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:38:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 10:07:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
#include "libms.h"
#include "setup.h"
#include <readline/readline.h>
#include <unistd.h>

char	*ms_readline(const char *prompt)
{
	char	*line;
	int 	dupped_fd;

	if (ms_is_interactive())
		return (readline(prompt));
	dupped_fd = dup(1);
	if (dupped_fd == -1)
		return (NULL);
	close(1);
	line = readline(NULL);
	dup2(dupped_fd, 1);
	return (line);
}
