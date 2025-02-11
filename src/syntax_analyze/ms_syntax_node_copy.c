/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:11:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 20:03:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "lexer.h"
#include "libms.h"

static t_syntax_node	**ms_syntax_node_children_copy(
							t_syntax_node **children);

t_syntax_node	*ms_syntax_node_copy(t_syntax_node *node)
{
	t_syntax_node	*new_node;

	new_node = ms_syntax_node_create(node->type);
	if (new_node == NULL)
		return (NULL);
	new_node->type = node->type;
	new_node->start_pos = node->start_pos;
	new_node->end_pos = node->end_pos;
	if (node->token)
	{
		new_node->token = ms_dup_token(node->token);
		if (new_node->token == NULL)
			return (ms_syntax_node_destroy(new_node), NULL);
	}
	if (node->children)
	{
		new_node->children = ms_syntax_node_children_copy(node->children);
		if (new_node->children == NULL)
			return (ms_syntax_node_destroy(new_node), NULL);
	}
	return (new_node);
}

static t_syntax_node	**ms_syntax_node_children_copy(
							t_syntax_node **children)
{
	t_syntax_node	**new_children;
	size_t			lst_size;
	size_t			i;

	lst_size = ms_ntpsize((void **)children);
	new_children = ft_calloc(lst_size + 1, sizeof(t_syntax_node *));
	if (new_children == NULL)
		return (NULL);
	i = 0;
	while (i < lst_size)
	{
		new_children[i] = ms_syntax_node_copy(children[i]);
		if (new_children[i] == NULL)
		{
			ms_destroy_ntp2(
				(void **)new_children, ms_syntax_node_destroy_wrapper);
			return (NULL);
		}
		i++;
	}
	new_children[i] = NULL;
	return (new_children);
}
