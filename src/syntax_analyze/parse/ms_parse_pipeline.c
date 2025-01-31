/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:38:25 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 16:06:50 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_pipeline(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node		*child2;
	t_syntax_node		*child3;
	t_syntax_node		*child4;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_blank(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_BLANK)
	{
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
	}
	else
		ms_syntax_node_destroy(child);
	if(tokens[pos] == NULL)
		return (ms_parse_declined(tokens, pos - 1));
	child = ms_parse_command(tokens, pos);
	if (child == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	if (child->type == SY_DECLINED)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
			ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	if (tokens[pos])
	{
		child = ms_parse_blank(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_BLANK)
		{
			ms_lstappend_tail(&child_lst, child,
				ms_syntax_node_destroy_wrapper);
			if (child_lst == NULL)
				return (ms_syntax_node_destroy(child), NULL);
			pos = child->end_pos;
		}
		else
			ms_syntax_node_destroy(child);
	}
	while (tokens[pos])
	{
		child = ms_parse_pipe(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			break ;
		}
		child2 = ms_parse_blank(tokens, child->end_pos);
		if (child2 == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				ms_syntax_node_destroy(child), NULL);
		if (child2->type == SY_DECLINED)
			ms_syntax_node_destroy(child2);
		if (child2)
			child3 = ms_parse_command(tokens, child2->end_pos);
		else
			child3 = ms_parse_command(tokens, child->end_pos);
		if (child3 == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2),
				NULL);
		if (child3->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			if (child2)
				ms_syntax_node_destroy(child2);
			ms_syntax_node_destroy(child3);
			break ;
		}
		if (tokens[child3->end_pos] != NULL)
		{
			child4 = ms_parse_blank(tokens, child3->end_pos);
			if (child4 == NULL)
				return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
					ms_syntax_node_destroy(child),
					ms_syntax_node_destroy(child2),
					ms_syntax_node_destroy(child3), NULL);
			if (child4->type == SY_DECLINED)
			{
				ms_syntax_node_destroy(child4);
				child4 = NULL;
			}
		}
		else
		{
			child4 = NULL;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		pos = child->end_pos;
		if (child2)
		{
			ms_lstappend_tail(&child_lst, child2,
				ms_syntax_node_destroy_wrapper);
			if (child_lst == NULL)
				return (ms_syntax_node_destroy(child2), NULL);
			pos = child2->end_pos;
		}
		ms_lstappend_tail(&child_lst, child3, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child3), NULL);
		pos = child3->end_pos;
		if (child4)
		{
			ms_lstappend_tail(&child_lst, child4,
				ms_syntax_node_destroy_wrapper);
			if (child_lst == NULL)
				return (ms_syntax_node_destroy(child4), NULL);
			pos = child4->end_pos;
		}
	}
	node = ms_syntax_node_create(SY_PIPELINE);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
