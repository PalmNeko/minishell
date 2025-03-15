/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:41:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 23:13:51 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_compound_list_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_blank, NULL},
	false,
	false}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func []){ms_parse_left_parenthesis, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_list, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func []){ms_parse_right_parenthesis, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func []){ms_parse_blank, NULL},
	false,
	false}},
	NULL
};

t_syntax_node	*ms_parse_compound_list(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_COMPOUND_LIST,
			(t_syntax_rule **)g_ms_compound_list_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
