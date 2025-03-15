/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_declined.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:33:21 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/09 04:23:59 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_declined(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_syntax_node_create(SY_DECLINED);
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
