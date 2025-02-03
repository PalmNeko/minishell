/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tilde_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:05:04 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 22:50:23 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static t_syntax_node	*ms_execution_tilde_expantion_quoted(t_syntax_node *word_list);
static t_syntax_node	*_ms_execution_tilde_expantion(t_syntax_node *word_node);

t_syntax_node	*ms_execution_tilde_expantion(t_syntax_node *word_list)
{
	int				i;
	t_syntax_node	*node;

	i = 0;
	while (word_list->children[i])
	{
		node = word_list->children[i];
		if (node->type == SY_DOUBLE_QUOTED_WORD
			|| node->type == SY_SINGLE_QUOTED_WORD)
		{
			node = ms_execution_tilde_expantion_quoted(node);
			if (node == NULL)
				return (NULL);
		}
		else
		{
			node = _ms_execution_tilde_expantion(node);
			if (node == NULL)
				return (NULL);
		}
		i++;
	}
	return (word_list);
}

static t_syntax_node	*ms_execution_tilde_expantion_quoted(t_syntax_node *word_list)
{
	int				i;
	t_syntax_node	*node;

	i = 0;
	if (word_list->type == SY_DOUBLE_QUOTED_WORD)
	{
		while (word_list->children[i])
		{
			if (word_list->children[i]->type != SY_DOUBLE_QUOTE)
			{
				node = word_list->children[i];
				node = _ms_execution_tilde_expantion(node);
				if (node == NULL)
					return (NULL);
				word_list->children[i] = node;
			}
			i++;
		}
	}
	return (word_list);
}

static t_syntax_node	*_ms_execution_tilde_expantion(t_syntax_node *word_node)
{
	char	*temp;

	temp = ms_tilde_expansion(word_node->token->token);
	if (temp == NULL)
		return (NULL);
	if (ft_strcmp(temp, word_node->token->token) == 0)
		free(temp);
	else
	{
		ms_lexical_analyze_destroy_token(word_node->token);
		word_node->token = ms_create_token(TK_WORD, temp, 0, ft_strlen(temp));
		if (word_node->token == NULL)
			return (NULL);
	}
	return (word_node);
}
