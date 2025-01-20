/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_truncate_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:20:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 11:16:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include "history.h"
#include "libft.h"
#include <stdlib.h>

void	ms_truncate_history(int nlines)
{
	t_history	history;

	history = ms_history();
	ms_truncate_history_history(&history, nlines);
	ms_set_history(&history);
	return ;
}
