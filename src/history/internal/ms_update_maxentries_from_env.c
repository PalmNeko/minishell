/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_update_maxentries_from_env.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:43:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 14:01:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal_type.h"
#include "libms.h"

void	ms_update_maxentries_from_env(t_history *history)
{
	if (ms_getenv("HISTSIZE") == NULL)
		history->history_max_entries = -1;
	else
		history->history_max_entries = ft_atoi(ms_getenv("HISTSIZE"));
}
