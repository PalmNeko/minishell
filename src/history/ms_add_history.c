/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:38:08 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 07:18:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include <readline/history.h>

void	ms_add_history(const char *string)
{
	t_history	history;

	history = ms_history();
	if (history.history_max_entries != 0)
		history.history_cmd++;
	ms_add_history_history(&history, string);
	add_history(string);
	ms_set_history(&history);
}
