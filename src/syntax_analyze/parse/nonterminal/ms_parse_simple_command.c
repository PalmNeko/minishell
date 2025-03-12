/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:59:36 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 00:10:14 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static t_syntax_node	*ms_parse_simple_command_tail(
							t_token **tokens, int pos);

static const t_parse_func	g_ms_simple_command_func_list[3] = {
	ms_parse_redirection_word,
	ms_parse_word_list,
	NULL
};

static const t_syntax_rule	*g_ms_simple_command_tail_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){
	ms_parse_blank, NULL},
	false,
	false}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func *)g_ms_simple_command_func_list,
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){
	ms_parse_blank, NULL},
	false,
	false}},
	NULL
};

static const t_syntax_rule	*g_ms_simple_command_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func *)g_ms_simple_command_func_list,
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_REPEAT,
	(t_parse_func []){
	ms_parse_simple_command_tail, NULL},
	true,
	true}},
	NULL
};

t_syntax_node	*ms_parse_simple_command(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_SIMPLE_COMMAND,
			(t_syntax_rule **)g_ms_simple_command_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_simple_command_tail(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_simple_command_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

// t_syntax_node	*ms_parse_simple_command(t_token **tokens, int pos)
// {
// 	t_syntax_node		*node;
// 	t_syntax_node		*child;
// 	t_syntax_node_list	*child_lst;
// 	const int			start_pos = pos;
// 	bool				is_blank;

// 	is_blank = false;
// 	child_lst = NULL;
// 	child = ms_parse_symbol_item(tokens, pos,
// 			g_ms_parse_simple_command_func_list);
// 	if (child == NULL)
// 		return (NULL);
// 	if (child->type == SY_DECLINED)
// 		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
// 	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child), NULL);
// 	pos = child->end_pos;
// 	is_blank = (tokens[pos] && tokens[pos]->type == TK_BLANK);
// 	while (tokens[pos + is_blank])
// 	{
// 		child = ms_parse_symbol_item(tokens, pos + is_blank,
// 				g_ms_parse_simple_command_func_list);
// 		if (child == NULL)
// 			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
// 				NULL);
// 		if (child->type == SY_DECLINED)
// 		{
// 			ms_syntax_node_destroy(child);
// 			break ;
// 		}
// 		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
// 		if (child_lst == NULL)
// 			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
// 				NULL);
// 		pos = child->end_pos;
// 		is_blank = (tokens[pos] && tokens[pos]->type == TK_BLANK);
// 	}
// 	node = ms_syntax_node_create_nonterminal(SY_SIMPLE_COMMAND, &child_lst,
// 			start_pos, pos);
// 	if (node == NULL)
// 		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
// 	return (node);
// }
