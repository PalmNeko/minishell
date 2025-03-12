/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_double_quoted_word.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:33:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/12 03:39:00 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static const t_parse_func	g_ms_double_quote_func_list[] = {
	ms_parse_double_quote,
	NULL
};

static const t_parse_func	g_ms_double_quoted_word_content_func_list[] = {
	ms_parse_blank,
	ms_parse_identify,
	ms_parse_single_quote,
	ms_parse_variable,
	ms_parse_newline,
	ms_parse_list_token,
	ms_parse_pipe,
	ms_parse_equal,
	ms_parse_redirection,
	ms_parse_left_parenthesis,
	ms_parse_right_parenthesis,
	ms_parse_word,
	NULL
};

static const t_syntax_rule	*g_ms_parse_double_quoted_word_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func *)g_ms_double_quote_func_list,
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_REPEAT,
	(t_parse_func *)g_ms_double_quoted_word_content_func_list,
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func *)g_ms_double_quote_func_list,
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_double_quoted_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_DOUBLE_QUOTED_WORD,
			(t_syntax_rule **)g_ms_parse_double_quoted_word_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
