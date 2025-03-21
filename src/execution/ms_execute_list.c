/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:37:50 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/16 02:25:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ms_execute_list(t_lsa_list *list)
{
	int	ret;

	ret = 0;
	if (list->pipeline)
		ret = ms_execute_pipeline(list->pipeline);
	else
		ret = ms_execute_compound_lists(list->compound_list);
	return (ret);
}
