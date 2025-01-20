/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clear_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:23:07 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 10:51:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "internal/history_internal.h"
#include <stdlib.h>

void	ms_clear_history(void)
{
	t_history	history;

	history = ms_history();
	ft_lstclear(&history.history, free);
	history.history_length = 0;
	ms_set_history(&history);
	return ;
}
