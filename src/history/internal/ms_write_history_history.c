/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_write_history_history.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:01:09 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 12:09:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal.h"
#include "libms.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

static int	ms_save_history(t_history *history, const char *filename);
static int	ms_save_history_fd(t_history *history, int fd);

int	ms_write_history_history(t_history *history, const char *filename)
{
	char	*save_filename;
	char	*tilde_expansion_path;
	int		eno;

	if (filename == NULL)
		save_filename = "~/.history";
	else
		save_filename = (char *)filename;
	tilde_expansion_path = ms_tilde_expansion(save_filename);
	if (tilde_expansion_path == NULL)
		return (errno);
	eno = ms_save_history(history, tilde_expansion_path);
	free(tilde_expansion_path);
	return (eno);
}

static int	ms_save_history(t_history *history, const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd == -1)
		return (errno);
	ms_save_history_fd(history, fd);
	close(fd);
	return (0);
}

static int	ms_save_history_fd(t_history *history, int fd)
{
	t_list	*history_list;

	history_list = history->history;
	while (history_list != NULL)
	{
		ft_putendl_fd(history_list->content, fd);
		history_list = history_list->next;
	}
	return (0);
}
