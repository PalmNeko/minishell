/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:32:03 by rnakatan         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (lsa_word_list->word_list->children[i])
		i++;
	expanded_texts = (char **)malloc(sizeof(char *) * (i + 1));
	if (expanded_texts == NULL)
		return (NULL);
	i = 0;
	while (lsa_word_list->word_list->children[i])
	{
		expanded_text = (char *)lsa_word_list->word_list->children[i]->token->token;
		expanded_texts[i] = expanded_text;
		i++;
	}
	expanded_texts[i] = NULL;
	return (expanded_texts);
}
