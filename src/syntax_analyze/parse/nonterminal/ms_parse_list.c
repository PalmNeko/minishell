/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:37:52 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 03:15:40 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static t_syntax_node	*ms_parse_list_tail(t_token **tokens, int pos);

static const t_parse_func	g_ms_parse_list_func_list[3] = {
	ms_parse_pipeline,
	ms_parse_compound_list,
	NULL
};

static const t_syntax_rule	*g_ms_list_tail_rule_list[3] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_list_token,
	NULL},
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_parse_list_func_list,
	false,
	true}},
	NULL
};

static const t_syntax_rule	*g_ms_list_rule_list[3] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_parse_list_func_list,
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_REPEAT,
	(t_parse_func[]){
	ms_parse_list_tail,
	NULL},
	true,
	true}},
	NULL
};

t_syntax_node	*ms_parse_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_LIST,
			(t_syntax_rule **)g_ms_list_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_list_tail(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_list_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
