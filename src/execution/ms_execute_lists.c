/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:29:32 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/28 05:45:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"

int	ms_execute_lists(t_lsa_list **lists)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (lists[i] && ms_has_meta(ret, IS_CHILD) == false)
	{
		if (lists[i]->type == LSA_LIST_ALWAYS
		|| (lists[i]->type == LSA_LIST_AND && ret == 0)
		|| (lists[i]->type == LSA_LIST_OR && ret != 0))
			ret = ms_execute_list(lists[i]);
		i++;
	}
	return (ret);
}
