/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parameter_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:03:38 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 23:00:22 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "setup.h"
#include <stdio.h>
#include <stdlib.h>

static t_syntax_node	*_ms_parameter_expansion(t_syntax_node *word_list);

t_syntax_node	*ms_parameter_expansion(t_syntax_node *word_list)
{
	int				i;
	int				j;
	t_syntax_node	*node;

	i = 0;
	while (word_list->children[i])
	{
		node = word_list->children[i];
		if (node->type == SY_DOUBLE_QUOTED_WORD)
		{
			j = 0;
			while (node->children[j])
			{
				node->children[j] = _ms_parameter_expansion(node->children[j]);
				j++;
			}
		}
		else
		{
			node = _ms_parameter_expansion(node);
		}
		i++;
	}
	return (word_list);
}

static t_syntax_node	*_ms_parameter_expansion(t_syntax_node *word_list_item_node)
{
	char	*word;

	if (word_list_item_node->type == SY_VARIABLE)
	{
		word = ms_getenv(&word_list_item_node->token->token[1]);
		if (word == NULL)
			word = ft_strdup("");
		else
			word = ft_strdup(word);
		if (word == NULL)
			return (NULL);
		free((void *)word_list_item_node->token->token);
		word_list_item_node->token->token = word;
	}
	return (word_list_item_node);
}
