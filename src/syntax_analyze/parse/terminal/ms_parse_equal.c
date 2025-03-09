/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:36:13 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 21:23:03 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_equal(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	if (tokens[pos]->type != TK_EQUALS)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_EQUALS);
	if (node == NULL)
		return (NULL);
	node->token = ms_duplicate_token(tokens[pos]);
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
