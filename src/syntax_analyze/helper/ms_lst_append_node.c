/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lst_append_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:57:04 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 21:01:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "syntax_analyze.h"

/**
 * duplicate with ms_lstappend_tail...
 * i want to remove this function
 */
int	ms_lst_append_node(t_list **lst, t_syntax_node *node)
{
	t_list	*new;

	new = ft_lstnew(node);
	if (new == NULL)
	{
		ft_lstclear(lst, ms_syntax_node_destroy_wrapper);
		return (-1);
	}
	ft_lstadd_back(lst, new);
	return (0);
}
