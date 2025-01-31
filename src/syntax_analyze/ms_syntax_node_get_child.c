/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_get_child.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:09:08 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 10:39:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

t_syntax_node	*ms_syntax_node_get_child(
					t_syntax_node *node, t_syntax_type type)
{
	int	pos;

	pos = 0;
	if (node -> children == NULL)
		return (NULL);
	while (node->children[pos] != NULL)
	{
		if (node->children[pos]->type == type)
			return (node->children[pos]);
		pos++;
	}
	return (NULL);
}
