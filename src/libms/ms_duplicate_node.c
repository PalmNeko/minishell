/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_diplicate_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:21:53 by nyts              #+#    #+#             */
/*   Updated: 2025/02/19 17:03:13 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_duplicate_node(t_syntax_node *node)
{
	t_syntax_node	*new_node;
	int				i;

	new_node = ms_syntax_node_create(node->type);
	if (new_node == NULL)
		return (NULL);
	if (node->children != NULL)
	{
		i = 0;
		new_node->children = (t_syntax_node **)
			malloc(sizeof(t_syntax_node *) * 100);
		while (node->children[i] != NULL)
		{
			new_node->children[i] = ms_duplicate_node(node->children[i]);
			if (new_node->children[i] == NULL)
				return (NULL);
			i++;
		}
		new_node->children[i] = NULL;
	}
	if (node->token != NULL)
		new_node->token = ms_dup_token(node->token);
	new_node->start_pos = node->start_pos;
	new_node->end_pos = node->end_pos;
	return (new_node);
}
