/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_next_line_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:58:21 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 10:58:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libft.h"
#include "semantic_analyze.h"

t_list	*ms_get_next_line_node(void)
{
	t_syntax_node	*node;
	t_list			*lst;
	t_list			*newlst;

	lst = NULL;
	node = ms_read_node();
	while (node != NULL)
	{
		newlst = ft_lstnew(node);
		if (newlst == NULL)
			break ;
		ft_lstadd_back(&lst, newlst);
		if (ft_strcmp(node->token->token, "\n") == 0)
			break ;
		node = ms_read_node();
	}
	return (lst);
}
