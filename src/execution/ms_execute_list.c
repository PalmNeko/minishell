/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:37:50 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/29 12:39:15 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <readline.h>
#include <signal.h>
#include <stdlib.h>

int	ms_execute_list(t_lsa_list *list)
{
	int	ret;

	if (list->pipeline)
	{
		ret = ms_execute_pipeline(list->pipeline);
		ms_set_exit_status(ret);
	}
	else
		ret = ms_execute_compound_lists(list->compound_list);
	return (ret);
}
