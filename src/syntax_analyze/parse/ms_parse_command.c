/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:38:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:38:38 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_command(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;
	bool				is_blank;

	is_blank = false;
	child_lst = NULL;
	// call mkmemscorp
	child = ms_parse_assignment_command(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		ms_syntax_node_destroy(child);
	else
	{
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
	}
	is_blank = (tokens[pos] && tokens[pos]->type == TK_BLANK);
	while (tokens[pos + is_blank])
	{
		child = ms_parse_simple_command(tokens, pos + is_blank);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			if (child_lst == NULL)
				return (ms_parse_declined(tokens, pos + is_blank));
			break ;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		pos = child->end_pos;
		is_blank = (tokens[pos] && tokens[pos]->type == TK_BLANK);
	}
	node = ms_syntax_node_create_nonterminal(SY_COMMAND, &child_lst, start_pos,
			pos);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}
