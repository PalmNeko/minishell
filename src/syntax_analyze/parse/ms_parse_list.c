/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:37:52 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:37:53 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

const t_parse_func	g_ms_parse_list_func_list[3] = {ms_parse_compound_list,
		ms_parse_pipeline, NULL};

t_syntax_node	*ms_parse_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node		*child2;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	if (tokens[pos] == NULL)
		return (ms_parse_declined(tokens, pos));
	child = ms_parse_symbol_item(tokens, pos, g_ms_parse_list_func_list);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	while (tokens[pos])
	{
		child = ms_parse_list_token(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_DECLINED || tokens[child->end_pos] == NULL)
		{
			ms_syntax_node_destroy(child);
			break ;
		}
		child2 = ms_parse_symbol_item(tokens, child->end_pos,
				g_ms_parse_list_func_list);
		if (child2 == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child2->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			ms_syntax_node_destroy(child2);
			break ;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		ms_lstappend_tail(&child_lst, child2, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child2), NULL);
		pos = child2->end_pos;
	}
	node = ms_syntax_node_create(SY_LIST);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
