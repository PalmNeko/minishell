/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_word_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:50 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/09 11:04:54 by rnakatan         ###   ########.fr       */
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

static const t_syntax_rule	*g_ms_parse_wordlist_rule_list[3] = {
	(const t_syntax_rule *)(const t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func *)g_ms_parse_wordlist_func_list,
	false,
	true}},
	(const t_syntax_rule *)(const t_syntax_rule[]){{
	EBNF_REPEAT,
	(t_parse_func *)g_ms_parse_wordlist_func_list,
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_word_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_WORD_LIST,
			(t_syntax_rule **)g_ms_parse_wordlist_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
