/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:29:32 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:33:03 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ms_execute_lists(t_lsa_list **lists)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (lists[i])
	{
		if (lists[i]->type == LSA_LIST_AND && ret != 0)
			break ;
		if (lists[i]->type == LSA_LIST_OR && ret == 0)
			break ;
		ret = ms_execute_list(lists[i]);
		i++;
	}
	return (ret);
}
