/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_user_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 03:04:50 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_user_input_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func []){ms_parse_all, NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_REPEAT,
	(t_parse_func []){ms_parse_all, NULL},
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_user_input(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_USER_INPUT,
			(t_syntax_rule **)g_ms_user_input_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
