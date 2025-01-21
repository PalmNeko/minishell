/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_user_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/21 23:39:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_user_input(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_all(tokens, pos);
	if (child == NULL)
		return (NULL);
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	while (tokens[pos])
	{
		child = ms_parse_all(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
	}
	node = ms_syntax_node_create(SY_USER_INPUT);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}
