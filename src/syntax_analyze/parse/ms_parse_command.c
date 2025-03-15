/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:38:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 19:24:51 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static t_syntax_node	*ms_parse_command_tail(t_token **tokens, int pos);

static const t_parse_func	g_ms_command_head_func_list[3] = {
	ms_parse_assignment_command,
	ms_parse_simple_command,
	NULL
};

static const t_syntax_rule	*g_ms_command_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func *)g_ms_command_head_func_list,
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_REPEAT,
	(t_parse_func[]){
	ms_parse_command_tail,
	NULL},
	true,
	true}},
	NULL
};

static const t_syntax_rule	*g_ms_command_tail_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_simple_command,
	NULL},
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_command(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_COMMAND,
			(t_syntax_rule **)g_ms_command_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_command_tail(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_command_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
