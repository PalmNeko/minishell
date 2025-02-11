/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:04:51 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 22:55:07 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexer.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static char		*ms_quote_removal_get_word(t_syntax_node *word_node);

t_syntax_node	*ms_quote_removal(t_syntax_node *word_list)
{
	int				i;
	char			*word;
	t_token			*token;
	t_syntax_node	*child_node;
	t_syntax_node	*new_word_node;

	i = 0;
	while (word_list->children[i])
	{
		child_node = word_list->children[i];
		if (child_node->type == SY_DOUBLE_QUOTED_WORD
			|| child_node->type == SY_SINGLE_QUOTED_WORD)
		{
			word = ms_quote_removal_get_word(child_node);
			if (word == NULL)
				return (NULL);
			token = ms_create_token(TK_WORD, word, 0, ft_strlen(word));
			free(word);
			if (token == NULL)
				return (NULL);
			new_word_node = ms_syntax_node_create(SY_WORD);
			if (new_word_node == NULL)
				return (NULL);
			new_word_node->token = token;
			new_word_node->start_pos = child_node->start_pos;
			new_word_node->end_pos = child_node->end_pos;
			ms_syntax_node_destroy(child_node);
			word_list->children[i] = new_word_node;
		}
		i++;
	}
	return (word_list);
}

char	*ms_quote_removal_get_word(t_syntax_node *quoted_word_node)
{
	t_syntax_node	*child_node;
	char			*word;
	char			*temp;
	int				i;
	t_syntax_type	type;

	word = ft_strdup("");
	if (word == NULL)
		return (NULL);
	type = quoted_word_node->children[0]->type;
	i = 1;
	while (quoted_word_node->children[i]->type != type)
	{
		child_node = quoted_word_node->children[i];
		temp = ft_strjoin(word, child_node->token->token);
		if (temp == NULL)
			return (NULL);
		free(word);
		word = temp;
		i++;
	}
	return (word);
}
