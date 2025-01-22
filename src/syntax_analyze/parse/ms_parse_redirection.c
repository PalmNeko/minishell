/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:12 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 00:19:10 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_redirection(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	if (tokens[pos]->type != TK_REDIRECTION)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_REDIRECTION);
	if (node == NULL)
		return (NULL);
	node->token = tokens[pos];
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
