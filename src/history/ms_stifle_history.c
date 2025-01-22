/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_stifle_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 08:13:36 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:14:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include <readline/readline.h>

void	ms_stifle_history(int max)
{
	t_history	history;

	history = ms_history();
	ms_stifle_history_history(&history, max);
	if (max == 0)
		rl_clear_history();
	ms_set_history(&history);
	return ;
}
