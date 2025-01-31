/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_right_parenthesis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:16 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 15:52:29 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_right_parenthesis(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	if (tokens[pos]->type != TK_RIGHT_PARENTHESIS)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_RIGHT_PARENTHESIS);
	if (node == NULL)
		return (NULL);
	node->token = ms_dup_token(tokens[pos]);
	if(node->token == NULL)
	{
		ms_syntax_node_destroy(node);
		return (NULL);
	}
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
