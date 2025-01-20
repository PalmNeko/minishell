/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reset_histcmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 06:02:16 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:03:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"

void	ms_reset_histcmd(void)
{
	t_history	history;

	history = ms_history();
	history.history_cmd = 0;
	ms_set_history(&history);
}
