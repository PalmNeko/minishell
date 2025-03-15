/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_ebnf_one_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/09 03:26:42 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include "syntax_analyze.h"

// -2 syntax_error
// -1 ENOMEM
// 0 > endpos
int	ms_parse_ebnf_one_method(t_token **tokens, int pos, t_list **syntax_lst,
		t_parse_func *parsers)
{
	t_syntax_node	*node;

	if (tokens[pos] == NULL)
		return (-2);
	node = ms_parse_symbol_item(tokens, pos, parsers);
	if (node == NULL)
		return (-1);
	if (node->type == SY_DECLINED)
		return (ms_syntax_node_destroy(node), -2);
	if (ms_lst_append_node(syntax_lst, node) == -1)
		return (ms_syntax_node_destroy(node), -1);
	return (node->end_pos);
}
