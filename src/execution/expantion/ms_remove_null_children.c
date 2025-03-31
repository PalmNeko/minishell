/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_null_children.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:07:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 14:55:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libms.h"

static int	ms_node_is_not_null(const t_syntax_node *node);

t_syntax_node	*ms_remove_null_children(t_syntax_node *node)
{
	t_syntax_node	*filtered_node;

	filtered_node = ms_syntax_node_filter(node, ms_node_is_not_null);
	if (filtered_node == NULL)
		return (NULL);
	ms_syntax_node_ntp_destroy(node->children);
	node->children = filtered_node->children;
	filtered_node->children = NULL;
	ms_syntax_node_destroy(filtered_node);
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
