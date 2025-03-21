/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:10:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 13:45:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

/**
 * Add the contents of filename to the history list, a line at a time.
 * If filename is NULL, then read from ~/.history. Returns 0 if successful, or
 * errno if not.
 */
int	ms_read_history(const char *filename)
{
	int			ret_errno;
	t_history	history;
	t_list		*history_list;

	history = ms_history();
	ms_update_maxentries_from_env(&history);
	ret_errno = ms_read_history_history(&history, filename);
	history_list = history.history;
	while (history_list != NULL)
	{
		add_history(history_list->content);
		history_list = history_list->next;
	}
	ms_set_history(&history);
	return (ret_errno);
}
