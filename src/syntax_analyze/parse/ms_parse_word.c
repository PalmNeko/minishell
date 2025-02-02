/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:54 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:37:14 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_word(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	if (tokens[pos]->type != TK_WORD)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_WORD);
	if (node == NULL)
		return (NULL);
	node->token = ms_dup_token(tokens[pos]);
	if (node->token == NULL)
	{
		ms_syntax_node_destroy(node);
		return (NULL);
	}
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
