/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 00:17:29 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexer.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

char	**ms_expansion(t_lsa_word_list *lsa_word_list)
{
	char	**expanded_texts;
	char	*expanded_text;
	char *temp;
	char *token;
	size_t	i;
	size_t	j;

	lsa_word_list->word_list = ms_execution_tilde_expantion(lsa_word_list->word_list);
	lsa_word_list->word_list = ms_parameter_expansion(lsa_word_list->word_list);
	lsa_word_list->word_list = ms_pathname_expansion(lsa_word_list->word_list);
	lsa_word_list->word_list = ms_quote_removal(lsa_word_list->word_list);
	i = 0;
	expanded_text = ft_strdup("");
	if (expanded_text == NULL)
		return (NULL);
	while (lsa_word_list->word_list->children[i])
	{
		j = 0;
		if(lsa_word_list->word_list->children[i]->children != NULL)
		{
			while(lsa_word_list->word_list->children[i]->children[j] != NULL)
			{
				token = (char *)lsa_word_list->word_list->children[i]->children[j]->token->token;
				temp = ft_strjoin(expanded_text, token);
				if (temp == NULL)
					return (NULL);
				free(expanded_text);
				expanded_text = temp;
				j++;
			}
		}else{
			token = (char *)lsa_word_list->word_list->children[i]->token->token;
			temp = ft_strjoin(expanded_text, token);
			if (temp == NULL)
				return (NULL);
			free(expanded_text);
			expanded_text = temp;
		}
		i++;
	}
	expanded_texts = ft_split(expanded_text, ' ');
	free(expanded_text);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}
