/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_analyze.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:28:00 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 22:09:53 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <syntax_analyze.h>

t_syntax_node	*ms_syntax_analyze(t_token **tokens)
{
	t_syntax_node	*node;
	int				pos;

	node = ms_parse_instruction(tokens, 0);
	if (node == NULL)
		return (NULL);
	if (tokens[node->end_pos] != NULL)
	{
		pos = node->end_pos;
		ms_syntax_node_destroy(node);
		node = ms_parse_declined(tokens, pos);
	}
	if (node->type == SY_DECLINED)
		printf("minishell: syntax error near unexpected token `%s\'\n",
			node->token->token);
	return (node);
}
