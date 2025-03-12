/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_assignment_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:40:11 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 03:17:21 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static t_syntax_node		*ms_parse_assignment_command_tail(
								t_token **tokens, int pos);

static const t_parse_func	g_ms_assignment_word_func_list[2] = {
	ms_parse_assignment_word,
	NULL
};

static const t_syntax_rule	*g_ms_assignment_command_tail_rule_list[] = {
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_assignment_word_func_list,
	false,
	true}},
	NULL
};

static const t_syntax_rule	*g_ms_assignment_command_rule_list[3] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_assignment_word,
	NULL},
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_REPEAT,
	(t_parse_func[]){
	ms_parse_assignment_command_tail,
	NULL},
	true,
	true}},
	NULL
};

t_syntax_node	*ms_parse_assignment_command(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_ASSIGNMENT_COMMAND,
			(t_syntax_rule **)g_ms_assignment_command_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_assignment_command_tail(
							t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules (tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_assignment_command_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
