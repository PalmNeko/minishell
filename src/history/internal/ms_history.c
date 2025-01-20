/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:28:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 05:49:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal_type.h"

static t_history	g_history = {
	.history = NULL,
	.history_length = 0,
	.history_max_entries = 0,
};

t_history	ms_history(void)
{
	return (g_history);
}

void	ms_set_history(const t_history *history)
{
	g_history = *history;
}
