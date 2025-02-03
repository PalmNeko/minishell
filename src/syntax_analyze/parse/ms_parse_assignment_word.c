/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_assignment_word.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:19:49 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 21:19:50 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

t_syntax_node	*ms_parse_assignment_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_assignment_word_name(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	if (tokens[pos] == NULL)
	{
		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		return (ms_parse_declined(tokens, start_pos));
	}
	child = ms_parse_equal(tokens, pos);
	if (child == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	if (child->token->type != TK_EQUALS)
		return (ms_syntax_node_destroy(child), ft_lstclear(&child_lst,
				ms_syntax_node_destroy_wrapper), ms_parse_declined(tokens,
				pos));
	ft_lstadd_back(&child_lst, ft_lstnew(child));
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	if (tokens[pos] == NULL)
	{
		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		return (ms_parse_declined(tokens, start_pos));
	}
	child = ms_parse_word_list(tokens, pos);
	if (child == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	node = ms_syntax_node_create_nonterminal(SY_ASSIGNMENT_WORD, &child_lst,
			start_pos, pos);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}
