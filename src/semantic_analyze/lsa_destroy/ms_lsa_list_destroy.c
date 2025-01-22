/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_list_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:12:51 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:12:52 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

static void	ms_lsa_list_destroy_wrapper(void *list);

void	ms_lsa_list_destroy(t_lsa_list *list)
{
	if (list == NULL)
		return ;
	if (list->pipeline != NULL)
		ms_lsa_pipeline_destroy(list->pipeline);
	if (list->compound_list != NULL)
		ms_destroy_ntp2((void **)list->compound_list,
			ms_lsa_list_destroy_wrapper);
	free(list);
}

static void	ms_lsa_list_destroy_wrapper(void *list)
{
	ms_lsa_list_destroy((t_lsa_list *)list);
}
