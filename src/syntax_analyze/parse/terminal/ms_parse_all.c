/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:31:30 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/08 20:44:45 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static const t_parse_func	g_ms_parse_all_func_list[] = {
	ms_parse_blank,
	ms_parse_identify,
	ms_parse_double_quote,
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

t_syntax_node	*ms_parse_all(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_parse_symbol_item(tokens, pos, g_ms_parse_all_func_list);
	if (node == NULL)
		return (NULL);
	return (node);
}
