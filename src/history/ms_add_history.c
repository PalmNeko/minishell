/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:38:08 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 10:07:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include <readline/history.h>

void	ms_add_history(const char *string)
{
	t_history	history;

	history = ms_history();
	ms_add_history_history(&history, string);
	add_history(string);
	ms_set_history(&history);
}
