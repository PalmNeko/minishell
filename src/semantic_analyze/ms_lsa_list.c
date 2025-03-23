/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/16 02:23:31 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include <stdlib.h>

static t_lsa_list	*ms_create_lsa_list(void);

t_lsa_list	*ms_lsa_list(t_syntax_node *list_node)
{
	t_lsa_list		*lsa_list;
	t_lsa_list		**compound_list;
	t_lsa_pipeline	*lsa_pipeline;

	lsa_list = ms_create_lsa_list();
	if (lsa_list == NULL)
		return (NULL);
	if (list_node->type == SY_PIPELINE)
	{
		lsa_pipeline = ms_lsa_pipeline(list_node);
		if (lsa_pipeline == NULL)
			return (NULL);
		lsa_list->pipeline = lsa_pipeline;
	}
	else if (list_node->type == SY_COMPOUND_LIST)
	{
		compound_list = ms_lsa_lists(list_node->children[1]);
		if (compound_list == NULL)
			return (NULL);
		lsa_list->compound_list = compound_list;
	}
	return (lsa_list);
}

static t_lsa_list	*ms_create_lsa_list(void)
{
	t_lsa_list	*lsa_list;

	lsa_list = malloc(sizeof(t_lsa_list));
	if (lsa_list == NULL)
		return (NULL);
	lsa_list->type = LSA_LIST_ALWAYS;
	lsa_list->pipeline = NULL;
	lsa_list->compound_list = NULL;
	return (lsa_list);
}
