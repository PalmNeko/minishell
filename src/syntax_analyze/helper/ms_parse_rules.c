/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:56:33 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 17:24:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

t_syntax_node	*ms_parse_rules(
					t_token **tokens,
					int pos,
					t_syntax_type type,
					t_syntax_rule **rules)
{
	t_syntax_node	*node;
	t_list			*child_lst;
	int				end_pos;

	child_lst = NULL;
	end_pos = pos;
	while (*rules != NULL)
	{
		end_pos = ms_parse_rule(tokens, end_pos, &child_lst, *rules);
		if (end_pos < 0)
			ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		if (end_pos == -1)
			return (NULL);
		else if (end_pos == -2)
			return (ms_parse_declined(tokens, pos));
		rules++;
	}
	node = ms_syntax_node_create_nonterminal(type, &child_lst, pos, end_pos);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}
