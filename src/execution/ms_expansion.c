/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 22:58:11 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexer.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static t_syntax_node	*ms_duplicate_node(t_syntax_node *node){
	t_syntax_node	*new_node;
	int				i;

	new_node = ms_syntax_node_create(node->type);
	if (new_node == NULL)
		return (NULL);
	if(node->children != NULL)
	{
		i = 0;
		new_node->children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * 100);
		while (node->children[i] != NULL)
		{
			new_node->children[i] = ms_duplicate_node(node->children[i]);
			if (new_node->children[i] == NULL)
				return (NULL);
			i++;
		}
		new_node->children[i] = NULL;	
	}
	if(node->token != NULL)
		new_node->token = ms_dup_token(node->token);
	new_node->start_pos = node->start_pos;
	new_node->end_pos = node->end_pos;
	return (new_node);
}

char	**ms_expansion(t_lsa_word_list *lsa_word_list)
{
	char			**expanded_texts;
	char			*expanded_text;
	char			*temp;
	char			*token;
	t_syntax_node	*word_list_node;
	size_t			i;

	word_list_node = ms_duplicate_node(lsa_word_list->word_list);
	word_list_node = ms_execution_tilde_expantion(word_list_node);
	word_list_node = ms_parameter_expansion(word_list_node);
	word_list_node = ms_pathname_expansion(word_list_node);
	word_list_node = ms_quote_removal(word_list_node);
	ms_syntax_node_print(word_list_node);
	i = 0;
	expanded_text = ft_strdup("");
	if (expanded_text == NULL)
		return (NULL);
	while (lsa_word_list->word_list->children[i])
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
