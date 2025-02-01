/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:59:36 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 11:03:35 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libms.h"
#include <stdlib.h>

static const t_parse_func g_ms_parse_simple_command_func_list[4] = {
	ms_parse_assignment_word,
	ms_parse_redirection_word,
	ms_parse_word_list,
	NULL
};

t_syntax_node *ms_parse_simple_command(t_token **tokens, int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
	t_syntax_node_list *child_lst;
	const int start_pos = pos;
	bool is_blank = false;

	child_lst = NULL;
	child = ms_parse_symbol_item(tokens, pos, g_ms_parse_simple_command_func_list);
	if (child == NULL)
		return (NULL);
	if(child->type == SY_DECLINED)
		return(ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if(child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	is_blank = (tokens[pos] && tokens[pos]->type == TK_BLANK);
	while(tokens[pos + is_blank])
	{
		child = ms_parse_symbol_item(tokens, pos + is_blank, g_ms_parse_simple_command_func_list);
		if (child == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		if(child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			break;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if(child_lst == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		pos = child->end_pos;
		is_blank = (tokens[pos]&&tokens[pos]->type == TK_BLANK);
	}
	node = ms_syntax_node_create_nonterminal(SY_SIMPLE_COMMAND, &child_lst, start_pos, pos);
	if(node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}

