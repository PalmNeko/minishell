/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_redirection_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:06 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 23:14:40 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_parse_redirection_word_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_redirection,
	NULL},
	false,
	true}},
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
	ms_parse_word_list,
	NULL},
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_redirection_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_REDIRECTION_WORD,
			(t_syntax_rule **)g_ms_parse_redirection_word_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
