/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:28:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 16:50:05 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "lexer.h"
#include <stdlib.h>

void	ms_syntax_node_destroy(t_syntax_node *node)
{
	int	i;

	if (node->children)
	{
		i = 0;
		while (node->children[i])
		{
			ms_syntax_node_destroy(node->children[i]);
			i++;
		}
		free(node->children);
	}
	else if (node->token)
		ms_lexical_analyze_destroy_token(node->token);
	free(node);
}
