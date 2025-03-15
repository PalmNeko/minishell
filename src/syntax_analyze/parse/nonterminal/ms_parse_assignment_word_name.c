/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_assignment_word_name.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:38:50 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/12 09:47:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_assignment_word_name_rule_list[2] = {
	(t_syntax_rule[]){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_identify,
	NULL},
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_assignment_word_name(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_WORD_LIST,
			(t_syntax_rule **)g_ms_assignment_word_name_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
