/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 02:08:48 by tookuyam         ###   ########.fr       */
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
static bool	ms_is_all_null_word(t_syntax_node *parent_node);
static char	*ms_get_expansion_string(t_syntax_node *word_list_node, int *index);

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
	char	**expanded_texts;
	char	*token_string;
	int		i;
	t_list	*expanded_text_lst;

	if (ms_is_all_null_word(word_list_node))
		return (ft_calloc(1, sizeof(char *)));
	expanded_text_lst = NULL;
	i = 0;
	while (word_list_node->children[i] != NULL)
	{
		if (word_list_node->children[i] != NULL)
		{
			token_string = ms_get_expansion_string(word_list_node, &i);
			if (token_string == NULL
				|| ms_lst_append_tail(&expanded_text_lst, token_string) == -1)
				return (free(token_string),
					ft_lstclear(&expanded_text_lst, free), NULL);
		}
	}
	expanded_texts = ms_lst_to_ntp(&expanded_text_lst, (void *)ft_strdup, free);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}

static bool	ms_is_all_null_word(t_syntax_node *parent_node)
{
	t_syntax_node	**children;
	int				index;

	index = 0;
	children = parent_node->children;
	while (children[index] != NULL)
	{
		if (children[index]->type != SY_NULL_WORD)
			return (false);
		index++;
	}
	return (true);
}

static char	*ms_get_expansion_string(t_syntax_node *word_list_node, int *index)
{
	char	*token_string;
	char	*cat_string;

	if (word_list_node->children[*index] == NULL)
		return (NULL);
	cat_string = ft_strdup(word_list_node->children[*index]->token->token);
	if (cat_string == NULL)
		return (NULL);
	(*index)++;
	while (ms_is_chain_node(word_list_node, *index))
	{
		token_string = (char *)word_list_node->children[*index]->token->token;
		if (ms_replace_joined_str(&cat_string, token_string) == NULL)
			return (free(cat_string), NULL);
		(*index)++;
	}
	return (cat_string);
}

static bool	ms_is_chain_node(t_syntax_node *parent_node, int index)
{
	t_syntax_node	**children;

	children = parent_node->children;
	if (children[index] == NULL)
		return (false);
	if (index == 0)
		return (true);
	if (children[index - 1]->end_pos == children[index]->start_pos)
		return (true);
	return (false);
}
