/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:28:20 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/21 23:28:21 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <syntax_analyze.h>

t_syntax_node	*ms_syntax_node_create(t_syntax_type type)
{
	t_syntax_node	*node;

	node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->children = NULL;
	node->token = NULL;
	return (node);
}
