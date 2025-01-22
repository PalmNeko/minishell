/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_history_history.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:26:55 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:43:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "history_internal.h"

void	ms_add_history_history(t_history *history, const char *string)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(string));
	if (new == NULL)
		return ;
	ft_lstadd_back(&history->history, new);
	history->history_length++;
	if (history->history_max_entries >= 0)
		ms_truncate_history_history(history, history->history_max_entries);
}
