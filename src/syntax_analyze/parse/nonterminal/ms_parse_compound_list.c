/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:41:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/12 09:31:13 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_compound_list_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_blank, NULL},
	false,
	false}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func []){ms_parse_left_parenthesis, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_list, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func []){ms_parse_right_parenthesis, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_blank, NULL},
	false,
	false}},
	NULL
};

t_syntax_node	*ms_parse_compound_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_COMPOUND_LIST,
			(t_syntax_rule **)g_ms_compound_list_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

// t_syntax_node	*ms_parse_compound_list(t_token **tokens, int pos)
// {
// 	t_syntax_node		*node;
// 	t_syntax_node		*child;
// 	t_syntax_node		*child2;
// 	t_syntax_node		*child3;
// 	t_syntax_node_list	*child_lst;
// 	const int			start_pos = pos;

// 	child_lst = NULL;
// 	pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
// 	child = ms_parse_left_parenthesis(tokens, pos);
// 	if (child == NULL)
// 		return (NULL);
// 	if (child->type == SY_DECLINED)
// 		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
// 	pos = child->end_pos;
// 	child2 = ms_parse_list(tokens, child->end_pos);
// 	if (child2 == NULL)
// 		return (ms_syntax_node_destroy(child), NULL);
// 	if (child2->type == SY_DECLINED)
// 	{
// 		ms_syntax_node_destroy(child);
// 		ms_syntax_node_destroy(child2);
// 		return (ms_parse_declined(tokens, pos));
// 	}
// 	pos = child2->end_pos;
// 	if (tokens[pos] == NULL)
// 		return (ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2),
// 			ms_parse_declined(tokens, pos - 1));
// 	child3 = ms_parse_right_parenthesis(tokens, child2->end_pos);
// 	if (child3 == NULL)
// 		return (ms_syntax_node_destroy(child), ms_syntax_node_destroy(child2),
// 			NULL);
// 	if (child3->type == SY_DECLINED)
// 	{
// 		ms_syntax_node_destroy(child);
// 		ms_syntax_node_destroy(child2);
// 		ms_syntax_node_destroy(child3);
// 		return (ms_parse_declined(tokens, child->end_pos));
// 	}
// 	pos = child3->end_pos;
// 	pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
// 	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child), NULL);
// 	ms_lstappend_tail(&child_lst, child2, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child2), NULL);
// 	ms_lstappend_tail(&child_lst, child3, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child3), NULL);
// 	node = ms_syntax_node_create_nonterminal(SY_COMPOUND_LIST, &child_lst,
// 			start_pos, pos);
// 	return (node);
// }
