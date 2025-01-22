/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clear_history_history.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:42:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 09:53:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_internal.h"
#include <stdlib.h>

void	ms_clear_history_history(t_history *history)
{
	ft_lstclear(&history->history, free);
	history->history_length = 0;
	history->history = NULL;
	return ;
}
