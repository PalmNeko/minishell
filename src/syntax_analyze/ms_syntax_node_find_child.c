/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_find_child.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:34:24 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 10:41:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

t_syntax_node	*ms_syntax_node_find_child(
					t_syntax_node *node, t_syntax_type type)
{
	t_syntax_node	*result;
	int				pos;

	pos = 0;
	if (node->type == type)
		return (node);
	if (node->children == NULL)
		return (NULL);
	while (node->children[pos] != NULL)
	{
		result = ms_syntax_node_find_child(node->children[pos], type);
		if (result != NULL)
			return (result);
		pos++;
	}
	return (NULL);
}
