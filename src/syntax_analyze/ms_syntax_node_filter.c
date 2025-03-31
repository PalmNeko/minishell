/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_filter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 15:00:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libms.h"
#include "syntax_analyze.h"

static int	ms_syntax_node_lstappend_tail(
				t_list **lst, const t_syntax_node *node);

t_syntax_node	*ms_syntax_node_filter(
					t_syntax_node *node, int (*filter)(const t_syntax_node *))
{
	t_list			*child_node_lst;
	t_syntax_node	**children_node;
	t_syntax_node	*new_node;

	if (node == NULL)
		return (NULL);
	child_node_lst = NULL;
	children_node = node->children;
	while (*children_node != NULL)
	{
		if (filter(*children_node))
		{
			if (ms_syntax_node_lstappend_tail(
					&child_node_lst, *children_node) == -1)
				return (ms_syntax_node_lstclear(&child_node_lst), NULL);
		}
		children_node++;
	}
	new_node = ms_syntax_node_create_nonterminal(
			node->type, &child_node_lst, node->start_pos, node->end_pos);
	ms_syntax_node_lstclear(&child_node_lst);
	if (new_node == NULL)
		return (NULL);
	return (new_node);
}

static int	ms_syntax_node_lstappend_tail(
				t_list **lst, const t_syntax_node *node)
{
	t_syntax_node	*new_node;

	new_node = ms_syntax_node_copy((t_syntax_node *)node);
	if (new_node == NULL)
		return (-1);
	if (ms_lst_append_tail(lst, new_node) == -1)
		return (ms_syntax_node_destroy(new_node), -1);
	return (0);
}
