/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_assignment_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:40:11 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 04:41:36 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libms.h"

t_syntax_node	*ms_parse_assignment_command(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_assignment_word(tokens, pos);
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
		if(tokens[pos]->type != TK_BLANK || tokens[pos + 1] == NULL)
			break ;
		child = ms_parse_assignment_word(tokens, pos + 1);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type != SY_DECLINED)
		{
			ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
			if (child_lst == NULL)
				return (ms_syntax_node_destroy(child), NULL);
			pos = child->end_pos;
		}
		else
			break ;
	}
	node = ms_syntax_node_create_nonterminal(SY_ASSIGNMENT_COMMAND, &child_lst, start_pos, pos);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}
