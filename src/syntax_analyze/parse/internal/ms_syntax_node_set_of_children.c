/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_set_of_children.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:42:27 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 00:20:28 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_syntax_node_set_of_children(t_syntax_node *node,
		t_syntax_node_list **child_lst)
{
	t_syntax_node	**children;

	children = (t_syntax_node **)ms_lst_to_ntp((t_list **)child_lst,
			ms_identify, ms_noop_del);
	if (children == NULL)
		return (ft_lstclear(child_lst, ms_syntax_node_destroy_wrapper), NULL);
	ft_lstclear(child_lst, ms_syntax_node_destroy_wrapper);
	node->children = children;
	return (node);
}
