/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unstifle_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 08:14:06 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 10:12:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"

int	unstifle_history(void)
{
	t_history	history;
	int			max_entries;

	history = ms_history();
	max_entries = ms_unstifle_history_history(&history);
	return (max_entries);
}
