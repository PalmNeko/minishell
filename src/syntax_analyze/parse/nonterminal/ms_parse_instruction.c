/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:37:11 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 23:14:10 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static t_syntax_node	*ms_parse_instruction_tail(t_token **tokens, int pos);

static const t_syntax_rule	*g_ms_instruction_tail_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_newline,
	NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_REPEAT,
	(t_parse_func[]){
	ms_parse_user_input,
	NULL},
	false,
	true}},
	NULL
};

static const t_syntax_rule	*g_ms_instruction_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_list,
	NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_instruction_tail,
	NULL},
	true,
	true}},
	NULL
};

t_syntax_node	*ms_parse_instruction(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_INSTRUCTION,
			(t_syntax_rule **)g_ms_instruction_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_instruction_tail(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_instruction_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
