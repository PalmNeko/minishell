/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_symbol_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:42:06 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 22:53:17 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

t_syntax_node	*ms_parse_symbol_item(t_token **tokens, int pos,
		const t_parse_func *func_list)
{
	t_syntax_node	*node;
	int				i;

	i = 0;
	while (func_list[i] && tokens[pos])
	{
		node = func_list[i](tokens, pos);
		if (node == NULL)
			return (NULL);
		if (node->type != SY_DECLINED)
			return (node);
		ms_syntax_node_destroy(node);
		i++;
	}
	return (ms_parse_declined(tokens, pos));
}
