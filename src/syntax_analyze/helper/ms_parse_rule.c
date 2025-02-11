/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:45:22 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 21:02:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "parse_helper.h"
#include "libms.h"

static t_parse_helper_func	ms_get_parse_func(t_ebnf_method method);
static t_syntax_node_list	*ms_syntax_node_lst_expand(t_syntax_node_list *lst);

// -1 ENOMEM
// -2 syntax_error
// -3 invalid rule method
int	ms_parse_rule(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_syntax_rule *rule)
{
	t_list				*rule_lst;
	t_list				*expanded_lst;
	t_parse_helper_func	parse_helper_f;
	int					new_pos;

	rule_lst = NULL;
	parse_helper_f = ms_get_parse_func(rule->method);
	if (parse_helper_f == NULL)
		return (-3);
	new_pos = parse_helper_f(tokens, pos, &rule_lst, rule->parsers);
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

static t_parse_helper_func	ms_get_parse_func(t_ebnf_method method)
{
	if (method == EBNF_ONE)
		return (ms_parse_ebnf_one_method);
	else if (method == EBNF_REPEAT)
		return (ms_parse_ebnf_repeat_method);
	else if (method == EBNF_OPTION)
		return (ms_parse_ebnf_option);
	else
		return (NULL);
}

static t_syntax_node_list	*ms_syntax_node_lst_expand(t_syntax_node_list *lst)
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
			if (copied == NULL
				|| ms_lst_append_node(&expanded_lst, copied) == -1)
				return (ft_lstclear(
						&expanded_lst, ms_syntax_node_destroy_wrapper), NULL);
			children++;
		}
		lst = lst->next;
	}
	return (expanded_lst);
}
