/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:04:51 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 00:45:16 by rnakatan         ###   ########.fr       */
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
	t_syntax_node	*node;

	i = 0;
	while (word_list->children[i])
	{
		node = word_list->children[i];
		if (node->type == SY_DOUBLE_QUOTED_WORD
			|| node->type == SY_SINGLE_QUOTED_WORD)
		{
			word = ms_quote_removal_get_word(node);
			if (word == NULL)
				return (NULL);
			token = ms_create_token(TK_WORD, word, 0, ft_strlen(word));
			if (token == NULL)
				return (NULL);
			node->type = SY_WORD;
			node->children = NULL;
			node->token = token;
		}
		i++;
	}
	return (word_list);
}

char	*ms_quote_removal_get_word(t_syntax_node *word_node)
{
	t_syntax_node	*node;
	char			*word;
	char			*temp;
	int				i;

	i = 0;
	word = ft_strdup("");
	while (word_node->children[i])
	{
		node = word_node->children[i];
		if (node->type != SY_DOUBLE_QUOTE && node->type != SY_SINGLE_QUOTE)
		{
			temp = ft_strjoin(word, node->token->token);
			if (temp == NULL)
				return (NULL);
			free(word);
			word = temp;
		}
		ms_syntax_node_destroy(node);
		i++;
	}
	return (word);
}
