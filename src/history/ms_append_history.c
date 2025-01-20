/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_append_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:43:41 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/19 12:01:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/history_internal.h"
#include "history.h"

int	ms_append_history(int nelements, const char *filename)
{
	t_history	history;
	int			eno;

	history = ms_history();
	eno = ms_append_history_history(&history, nelements, filename);
	return (eno);
}
