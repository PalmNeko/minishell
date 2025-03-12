/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:38:25 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 03:43:37 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static t_syntax_node	*ms_parse_pipeline_tail(t_token **tokens, int pos);

static const t_syntax_rule	*g_ms_pipeline_rule_list[] = {
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_command,
	NULL},
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule[]){{
	EBNF_REPEAT,
	(t_parse_func[]){
	ms_parse_pipeline_tail,
	NULL},
	true,
	true}},
	NULL
};

static const t_syntax_rule	*g_ms_pipeline_tail_rule_list[] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_pipe,
	NULL},
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_command,
	NULL},
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	NULL
};

t_syntax_node	*ms_parse_pipeline(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_PIPELINE,
			(t_syntax_rule **)g_ms_pipeline_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

static t_syntax_node	*ms_parse_pipeline_tail(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_rules(tokens, pos, SY_ACCEPTED,
			(t_syntax_rule **)g_ms_pipeline_tail_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
