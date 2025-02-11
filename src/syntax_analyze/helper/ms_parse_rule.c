/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:45:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 19:43:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "libms.h"

int	ms_parse_ebnf_repeat_method(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);
int	ms_parse_ebnf_option(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);
int	ms_parse_ebnf_one_method(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);

int	ms_lst_append(t_list **lst, void *content);
t_syntax_node_list	*ms_syntax_node_lst_expand(t_syntax_node_list *lst);

// -1 ENOMEM
// -2 syntax_error
// -3 invalid rule method
int	ms_parse_rule(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_syntax_rule *rule)
{
	t_list	*rule_lst;
	t_list	*expanded_lst;
	int		new_pos;

	rule_lst = NULL;
	if (rule->method == EBNF_ONE)
		new_pos = ms_parse_ebnf_one_method(tokens, pos, &rule_lst, rule->parsers);
	else if (rule->method == EBNF_REPEAT)
		new_pos = ms_parse_ebnf_repeat_method(tokens, pos, &rule_lst, rule->parsers);
	else if (rule->method == EBNF_OPTION)
		new_pos = ms_parse_ebnf_option(tokens, pos, &rule_lst, rule->parsers);
	else
		return (-3);
	if (new_pos < 0)
		return (new_pos);
	if (rule_lst != NULL && rule->enable_expansion)
	{
		expanded_lst = ms_syntax_node_lst_expand(rule_lst);
		ft_lstclear(&rule_lst, ms_syntax_node_destroy_wrapper);
		if (expanded_lst == NULL)
			return (-1);
	}
	else
		expanded_lst = rule_lst;
	if (expanded_lst != NULL)
		ft_lstadd_back(syntax_lst, expanded_lst);
	return (new_pos);
}

int	ms_parse_ebnf_repeat_method(
	t_token **tokens,
	int pos,
	t_list **syntax_lst,
	t_parse_func *parsers)
{
	t_list	*working_lst;
	int		end_pos;
	int		new_pos;

	working_lst = NULL;
	end_pos = pos;
	while (1)
	{
		new_pos = ms_parse_ebnf_one_method(
				tokens, end_pos, &working_lst, parsers);
		if (new_pos == -1)
			return (ft_lstclear(
					&working_lst, ms_syntax_node_destroy_wrapper), -1);
		else if (new_pos == -2)
			break ;
		end_pos = new_pos;
	}
	*syntax_lst = working_lst;
	return (end_pos);
}

int	ms_parse_ebnf_option(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers)
{
	int		end_pos;

	end_pos = pos;
	end_pos = ms_parse_ebnf_one_method(tokens, pos, syntax_lst, parsers);
	if (end_pos == -1)
		return (-1);
	if (end_pos == -2)
		return (pos);
	return (end_pos);
}

// -2 syntax_error
// -1 ENOMEM
// 1回は必ず現れる必要がある
int	ms_parse_ebnf_one_method(
					t_token **tokens,
					int pos,
					t_list **syntax_lst,
					t_parse_func *parsers)
{
	t_syntax_node	*node;

	if (tokens[pos] == NULL)
		return (-2);
	node = ms_parse_symbol_item(tokens, pos, parsers);
	if (node == NULL)
		return (-1);
	if (node->type == SY_DECLINED)
		return (ms_syntax_node_destroy(node), -2);
	if (ms_lst_append(syntax_lst, node) == -1)
		return (ms_syntax_node_destroy(node), -1);
	return (node->end_pos);
}

int	ms_lst_append(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
	{
		ft_lstclear(lst, ms_syntax_node_destroy_wrapper);
		return (-1);
	}
	ft_lstadd_back(lst, new);
	return (0);
}

t_syntax_node_list	*ms_syntax_node_lst_expand(t_syntax_node_list *lst)
{
	t_syntax_node_list	*expanded_lst;
	t_syntax_node		*node;
	t_syntax_node		**children;
	t_syntax_node		*copied;

	expanded_lst = NULL;
	while (lst != NULL)
	{
		node = lst->content;
		children = node->children;
		while (*children != NULL)
		{
			copied = ms_syntax_node_copy(*children);
			if (copied == NULL || ms_lst_append(&expanded_lst, copied) == -1)
				return (ft_lstclear(
						&expanded_lst, ms_syntax_node_destroy_wrapper), NULL);
			children++;
		}
		lst = lst->next;
	}
	return (expanded_lst);
}
