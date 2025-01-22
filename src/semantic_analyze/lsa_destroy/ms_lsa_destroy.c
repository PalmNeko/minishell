/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:12:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:12:45 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

void	ms_lsa_destroy(t_lsa *lsa)
{
	int	i;

	if (lsa == NULL)
		return ;
	i = 0;
	while (lsa->lists[i] != NULL)
	{
		ms_lsa_list_destroy(lsa->lists[i]);
		i++;
	}
	free(lsa->lists);
	free(lsa);
}
