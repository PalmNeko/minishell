/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_ebnf_one_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 20:59:07 by tookuyam         ###   ########.fr       */
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
