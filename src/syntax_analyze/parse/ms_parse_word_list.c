/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_word_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:50 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 19:36:39 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static const t_parse_func	g_ms_parse_wordlist_func_list[7] = {
	ms_parse_identify,
	ms_parse_word,
	ms_parse_variable,
	ms_parse_equal,
	ms_parse_single_quoted_word,
	ms_parse_double_quoted_word,
	NULL
};

t_syntax_node	*ms_parse_word_list(t_token **tokens, int pos)
{
	t_syntax_node_list	*child_lst;
	t_syntax_node		*child;
	t_syntax_node		*node;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_symbol_item(tokens, pos, g_ms_parse_wordlist_func_list);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	while (tokens[pos] && child->type != SY_DECLINED)
	{
		child = ms_parse_symbol_item(tokens, pos,
				g_ms_parse_wordlist_func_list);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		if (child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			break ;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
	}
	node = ms_syntax_node_create(SY_WORD_LIST);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
