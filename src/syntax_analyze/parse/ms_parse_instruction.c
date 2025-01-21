/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:37:11 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/21 23:37:17 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_instruction(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_list(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	if (tokens[pos] != NULL)
	{
		child = ms_parse_newline(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				ms_parse_declined(tokens, pos));
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
		if (tokens[pos] != NULL)
		{
			child = ms_parse_user_input(tokens, pos);
			if (child == NULL)
				return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
					NULL);
			ms_lstappend_tail(&child_lst, child,
				ms_syntax_node_destroy_wrapper);
			if (child_lst == NULL)
				return (ms_syntax_node_destroy(child), NULL);
			pos = child->end_pos;
		}
		if (tokens[pos] != NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				ms_parse_declined(tokens, pos));
	}
	node = ms_syntax_node_create(SY_INSTRUCTION);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
