/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_history_truncate_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:16:41 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 08:08:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "internal/history_internal.h"
#include <stdlib.h>

int	ms_history_truncate_file(const char *filename, int nlines)
{
	t_history	history;
	int			eno;

	ms_init_history(&history);
	history.history_max_entries = nlines;
	eno = ms_read_history_history(&history, filename);
	if (eno != 0)
		return (eno);
	ms_truncate_history_history(&history, nlines);
	eno = ms_write_history_history(&history, filename);
	if (eno != 0)
		return (eno);
	ms_clear_history_history(&history);
	return (0);
}
