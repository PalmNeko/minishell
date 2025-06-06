/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_double_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:33:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 21:23:03 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_double_quote(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	if (tokens[pos]->type != TK_DOUBLE_QUOTE)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_DOUBLE_QUOTE);
	if (node == NULL)
		return (NULL);
	node->token = ms_duplicate_token(tokens[pos]);
	if (node->token == NULL)
	{
		ms_syntax_node_destroy(node);
		return (NULL);
	}
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
