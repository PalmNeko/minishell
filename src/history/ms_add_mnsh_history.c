/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_mnsh_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:29:03 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 06:05:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include "history.h"
#include "libms.h"

void	ms_add_mnsh_history(const char *string)
{
	if (ms_unstifle_history() == 0)
		return ;
	ms_add_history(string);
}
