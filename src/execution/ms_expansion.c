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

char	**ms_expansion(t_lsa_word_list *lsa_word_list)
{
	char			**expanded_texts;
	char			*expanded_text;
	char			*temp;
	char			*token;
	t_syntax_node	*word_list_node;
	size_t			i;

	word_list_node = lsa_word_list->word_list;
	word_list_node = ms_execution_tilde_expantion(word_list_node);
	ms_syntax_node_print(word_list_node);
	word_list_node = ms_parameter_expansion(word_list_node);
	ms_syntax_node_print(word_list_node);
	word_list_node = ms_pathname_expansion(word_list_node);
	ms_syntax_node_print(word_list_node);
	word_list_node = ms_quote_removal(word_list_node);
	ms_syntax_node_print(word_list_node);
	i = 0;
	expanded_text = ft_strdup("");
	if (expanded_text == NULL)
		return (NULL);
	while (lsa_word_list->word_list->children[i])
	{
		token = (char *)lsa_word_list->word_list->children[i]->token->token;
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
