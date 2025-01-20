/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_history_stifle_history_history.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:38:59 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 09:53:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal.h"

void	ms_stifle_history_history(t_history *history, int max)
{
	history->history_max_entries = max;
}
