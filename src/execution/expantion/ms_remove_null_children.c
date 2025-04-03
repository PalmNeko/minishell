/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_null_children.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:07:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/03 08:43:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libms.h"

static int	ms_node_is_not_null(const t_syntax_node *node);

t_syntax_node	*ms_remove_null_children(t_syntax_node *node)
{
	t_syntax_node	**children;

	children = node->children;
	while (*children != NULL)
	{
		if (ms_node_is_not_null(*children) == 0)
			(*children)->type = SY_NULL_WORD;
		children++;
	}
	return (node);
}

static int	ms_node_is_not_null(const t_syntax_node *node)
{
	if (node == NULL)
		return (0);
	if (node->children != NULL)
		return (1);
	if (node->token != NULL && ft_strlen(node->token->token) > 0)
		return (1);
	return (0);
}
