/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:38:25 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 03:01:02 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_pipeline(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node		*child2;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;
	bool is_blank;

	child_lst = NULL;
	pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
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
	pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
	while (tokens[pos])
	{
		child = ms_parse_pipe(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		is_blank = (tokens[child->end_pos] && tokens[child->end_pos]->type == TK_BLANK);
		if (child->type == SY_DECLINED || tokens[child->end_pos + is_blank] == NULL)
		{
			ms_syntax_node_destroy(child);
			break ;
		}
		child2 = ms_parse_command(tokens, child->end_pos + is_blank);
		if (child2 == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				ms_syntax_node_destroy(child),NULL);
		if (child2->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			ms_syntax_node_destroy(child2);
			break ;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2), NULL);
		pos = child->end_pos;
		ms_lstappend_tail(&child_lst, child2, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child2), NULL);
		pos = child2->end_pos;
		pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
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
