/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:41:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/21 23:41:48 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_compound_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node		*child2;
	t_syntax_node		*child3;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_left_parenthesis(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	pos = child->end_pos;
	child2 = ms_parse_list(tokens, child->end_pos);
	if (child2 == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	if (child2->type == SY_DECLINED)
	{
		ms_syntax_node_destroy(child);
		ms_syntax_node_destroy(child2);
		return (ms_parse_declined(tokens, pos));
	}
	pos = child2->end_pos;
	if (tokens[pos] == NULL)
		return (ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2),
			ms_parse_declined(tokens, pos - 1));
	child3 = ms_parse_right_parenthesis(tokens, child2->end_pos);
	if (child3 == NULL)
		return (ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2),
			NULL);
	if (child3->type == SY_DECLINED)
	{
		ms_syntax_node_destroy(child);
		ms_syntax_node_destroy(child2);
		ms_syntax_node_destroy(child3);
		return (ms_parse_declined(tokens, pos));
	}
	pos = child3->end_pos;
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	ms_lstappend_tail(&child_lst, child2, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child2), NULL);
	ms_lstappend_tail(&child_lst, child3, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child3), NULL);
	node = ms_syntax_node_create(SY_COMPOUND_LIST);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
