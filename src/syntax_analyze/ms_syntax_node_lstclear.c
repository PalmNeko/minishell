/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_lstclear.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:19:10 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 14:20:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

void	ms_syntax_node_lstclear(t_syntax_node_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	ft_lstclear(lst, ms_syntax_node_destroy_wrapper);
	*lst = NULL;
}
