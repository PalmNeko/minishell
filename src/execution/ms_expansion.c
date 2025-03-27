/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/10 01:30:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexical_analyze.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

typedef t_syntax_node		*(*t_expand_func)(t_syntax_node *word_list_node);

static const t_expand_func	g_expand_funcs[] = {
	ms_execution_tilde_expantion,
	ms_parameter_expansion,
	ms_pathname_expansion,
	ms_quote_removal,
	NULL
};

static char	**ms_get_expand_texts(t_syntax_node *word_list_node);
static bool	ms_is_chain_node(t_syntax_node *parent_node, int index);
static int	ms_get_child_token_string(t_syntax_node *child_node,
				char **string_ptr, bool join_flag);

char	**ms_expansion(t_lsa_word_list *lsa_word_list)
{
	char			**expanded_texts;
	t_syntax_node	*word_list_node;
	size_t			i;

	word_list_node = ms_duplicate_node(lsa_word_list->word_list);
	if (word_list_node == NULL)
		return (NULL);
	i = 0;
	while (g_expand_funcs[i])
	{
		word_list_node = (*g_expand_funcs[i])(word_list_node);
		if (word_list_node == NULL)
			return (NULL);
		i++;
	}
	expanded_texts = ms_get_expand_texts(word_list_node);
	ms_syntax_node_destroy(word_list_node);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}

static char	**ms_get_expand_texts(t_syntax_node *word_list_node)
{
	char			**expanded_texts;
	char			*token_string;
	size_t			i;
	t_list			*expanded_text_lst;
	bool			join_flag;

	join_flag = false;
	expanded_text_lst = NULL;
	i = 0;
	while (word_list_node->children[i] != NULL)
	{
		if (ms_get_child_token_string(word_list_node->children[i],
				&token_string, join_flag) == -1)
			return (ft_lstclear(&expanded_text_lst, free), NULL);
		join_flag = ms_is_chain_node(word_list_node, i);
		if (!join_flag)
			if (ms_lst_append_tail(&expanded_text_lst, token_string) == -1)
				return (ft_lstclear(&expanded_text_lst, free), NULL);
		i++;
	}
	expanded_texts = ms_lst_to_ntp(&expanded_text_lst, (void *)ft_strdup, free);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}

static bool	ms_is_chain_node(t_syntax_node *parent_node, int index)
{
	return (parent_node->children[index + 1] != NULL
		&& (parent_node->children[index]->end_pos
			== parent_node->children[index + 1]->start_pos));
}

static int	ms_get_child_token_string(t_syntax_node *child_node,
	char **string_ptr, bool join_flag)
{
	const char	*token_string = child_node->token->token;

	if (join_flag)
	{
		if (ms_replace_joined_str(string_ptr, token_string) == NULL)
		{
			free(*string_ptr);
			*string_ptr = NULL;
		}
	}
	else
		*string_ptr = ft_strdup(token_string);
	if (*string_ptr == NULL)
		return (-1);
	return (0);
}
