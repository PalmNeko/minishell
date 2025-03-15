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

/*
空白区切りだと"  s"のような文字列が空白区切りで分割されてしまう
*/
static char	**ms_get_expand_texts(t_syntax_node *word_list_node)
{
	char			**expanded_texts;
	char			*expanded_text;
	char			*temp;
	char			*token;
	size_t			i;

	i = 0;
	expanded_text = ft_strdup("");
	if (expanded_text == NULL)
		return (NULL);
	while (word_list_node->children[i])
	{
		token = (char *)word_list_node->children[i]->token->token;
		temp = ft_strjoin(expanded_text, token);
		free(expanded_text);
		if (temp == NULL)
			return (NULL);
		expanded_text = temp;
		i++;
	}
	expanded_texts = ft_split(expanded_text, ' ');
	free(expanded_text);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}
