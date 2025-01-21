/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:31:30 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/21 23:32:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_all(t_token **tokens, int pos)
{
	t_syntax_node	*node;

	node = ms_syntax_node_create(SY_ALL);
	if (node == NULL)
		return (NULL);
	node->token = tokens[pos];
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
