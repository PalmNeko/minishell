/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_history_history.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:55:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 10:51:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "get_next_line.h"
#include "history_internal.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

int	ms_load_history_history(t_history *history, const char *filename);
int	ms_load_history_history_fd(t_history *history, int fd);

/**
 * Add the contents of filename to the history list, a line at a time.
 * If filename is NULL, then read from ~/.history. Returns 0 if successful, or
 * errno if not.
 */
int	ms_read_history_history(t_history *history, const char *filename)
{
	char	*read_file_name;
	int		ret_errno;

	if (filename == NULL)
		read_file_name = "~/.history";
	else
		read_file_name = (char *)filename;
	ret_errno = ms_load_history_history(history, read_file_name);
	return (ret_errno);
}

int	ms_load_history_history(t_history *history, const char *filename)
{
	int		fd;
	int		ret_errno;
	char	*tilde_expanded_filename;

	tilde_expanded_filename = ms_tilde_expansion(filename);
	if (tilde_expanded_filename == NULL)
		return (errno);
	fd = open(tilde_expanded_filename, O_RDONLY);
	if (fd == -1)
		return (errno);
	ret_errno = ms_load_history_history_fd(history, fd);
	close(fd);
	return (ret_errno);
}

int	ms_load_history_history_fd(t_history *history, int fd)
{
	char	*line;
	char	*carry_up;

	errno = 0;
	carry_up = NULL;
	while (1)
	{
		line = get_next_line2(fd, &carry_up);
		if (line == NULL)
			break ;
		ms_trim_end_newline(line);
		ms_add_history_history(history, line);
		free(line);
	}
	free(carry_up);
	return (0);
}
