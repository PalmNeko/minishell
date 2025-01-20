/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:08:23 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:28:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal.h"

void	ms_init_history(t_history *history)
{
	history->history = NULL;
	history->history_length = 0;
	history->history_max_entries = 0;
	history->history_cmd = 1;
	history->enable_history_cmd = true;
}
