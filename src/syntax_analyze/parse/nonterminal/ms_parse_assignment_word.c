/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_assignment_word.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:19:49 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/28 09:52:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_parse_func	g_ms_assignment_word_name_funcs[] = {
	ms_parse_assignment_word_name,
	NULL
};

static const t_parse_func	g_ms_assignment_word_equal_funcs[] = {
	ms_parse_equal,
	NULL
};

static const t_parse_func	g_ms_assignment_word_value_funcs[] = {
	ms_parse_word_list,
	NULL
};

static const t_syntax_rule	*g_ms_assignment_word_rule_list[] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_assignment_word_name_funcs,
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_assignment_word_equal_funcs,
	false,
	true}},
	(t_syntax_rule[]){{
	EBNF_OPTION,
	(t_parse_func *)g_ms_assignment_word_value_funcs,
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_assignment_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_ASSIGNMENT_WORD,
			(t_syntax_rule **)g_ms_assignment_word_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
