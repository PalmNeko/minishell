/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_redirection_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:39:06 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/12 09:39:01 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"

static const t_syntax_rule	*g_ms_parse_redirection_word_rule_list[] = {
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_redirection,
	NULL},
	false,
	true}},
	(t_syntax_rule []){{
	EBNF_OPTION,
	(t_parse_func[]){
	ms_parse_blank,
	NULL},
	false,
	false}},
	(t_syntax_rule []){{
	EBNF_ONE,
	(t_parse_func[]){
	ms_parse_word_list,
	NULL},
	false,
	true}},
	NULL
};

t_syntax_node	*ms_parse_redirection_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;

	node = ms_parse_rules(tokens, pos, SY_REDIRECTION_WORD,
			(t_syntax_rule **)g_ms_parse_redirection_word_rule_list);
	if (node == NULL)
		return (NULL);
	return (node);
}

// t_syntax_node	*ms_parse_redirection_word(t_token **tokens, int pos)
// {
// 	t_syntax_node		*node;
// 	t_syntax_node		*child;
// 	t_syntax_node_list	*child_lst;
// 	const int			start_pos = pos;

// 	child_lst = NULL;
// 	child = ms_parse_redirection(tokens, pos);
// 	if (child == NULL)
// 		return (NULL);
// 	if (child->token->type != TK_REDIRECTION)
// 		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
// 	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child), NULL);
// 	pos = child->end_pos;
// 	pos += (tokens[pos] && tokens[pos]->type == TK_BLANK);
// 	if (tokens[pos] == NULL)
// 	{
// 		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
// 		return (ms_parse_declined(tokens, pos - 1));
// 	}
// 	child = ms_parse_word_list(tokens, pos);
// 	if (child == NULL)
// 		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
// 	if (child->type == SY_DECLINED)
// 	{
// 		ms_syntax_node_destroy(child);
// 		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
// 		return (ms_parse_declined(tokens, pos));
// 	}
// 	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
// 	if (child_lst == NULL)
// 		return (ms_syntax_node_destroy(child), NULL);
// 	pos = child->end_pos;
// 	node = ms_syntax_node_create_nonterminal(SY_REDIRECTION_WORD, &child_lst,
// 			start_pos, pos);
// 	if (node == NULL)
// 		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
// 	return (node);
// }
