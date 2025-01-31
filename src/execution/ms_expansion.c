/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:03 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 13:38:22 by rnakatan         ###   ########.fr       */
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
	t_list	*expand_itr;
	char	*expanded_text;
	size_t	i;

	expand_itr = NULL;
	lsa_word_list->word_list = ms_execution_tilde_expantion(lsa_word_list->word_list);
	lsa_word_list->word_list = ms_parameter_expansion(lsa_word_list->word_list);
	// lsa_word_list->word_list = ms_pathname_expansion(lsa_word_list->word_list);s
	lsa_word_list->word_list = ms_quote_removal(lsa_word_list->word_list);
	i = 0;
	while (lsa_word_list->word_list->children[i])
	{
		expanded_text = ft_strdup(lsa_word_list->word_list->children[i]->token->token);
		if (expanded_text == NULL)
			return (NULL);
		ms_lstappend_tail(&expand_itr, expanded_text, free);
		if (expand_itr == NULL)
			return (NULL);
		i++;
	}
	expanded_texts = (char **)ms_lst_to_ntp(&expand_itr, ms_identify,
			ms_noop_del);
	if (expanded_texts == NULL)
		return (NULL);
	return (expanded_texts);
}
