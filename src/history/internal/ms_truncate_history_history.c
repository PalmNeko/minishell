/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_truncate_history_history.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:36:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 11:16:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal.h"
#include <stdlib.h>

void	ms_truncate_history_history(t_history *history, int nlines)
{
	t_list	*poped;

	if (nlines < 0)
		return ;
	while (history->history_length > nlines)
	{
		poped = ft_lstpop(&history->history);
		ft_lstdelone(poped, free);
		history->history_length--;
	}
	return ;
}
