/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_word_list_to_delimiter_string.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:31:33 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/28 08:15:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "syntax_analyze.h"
#include "semantic_analyze.h"
#include "libft.h"
#include "libms.h"
#include <stdlib.h>
#include <stdio.h>

static int	ms_replace_joined_str_quoted_word(
				char **left, const t_syntax_node *right);

/**
 * @brief デリミタワードリストを文字列に変換する
 */
char	*ms_word_list_to_delimiter_string(t_lsa_word_list *word_list)
{
	char			*delimiter;
	t_syntax_node	*wl_node;
	t_syntax_node	*inner_node;
	int				pos;

	delimiter = ft_strdup("");
	if (delimiter == NULL)
		return (NULL);
	wl_node = word_list->word_list;
	pos = 0;
	while (wl_node->children[pos] != NULL)
	{
		inner_node = wl_node->children[pos];
		if (inner_node->type == SY_DOUBLE_QUOTED_WORD
			|| inner_node->type == SY_SINGLE_QUOTED_WORD)
			ms_replace_joined_str_quoted_word(&delimiter, inner_node);
		else
		{
			if (ms_replace_joined_str(
					&delimiter, inner_node->token->token) == NULL)
				return (free(delimiter), NULL);
		}
		pos++;
	}
	return (delimiter);
}

/**
 * @param right expected type: SYNGLE_QUOTED_WORD or DOUBLE_QUOTED_WORD
 */
int	ms_replace_joined_str_quoted_word(char **left, const t_syntax_node *right)
{
	char			*quoted_word;
	int				pos;
	t_syntax_node	*all_node;

	quoted_word = ft_strdup("");
	if (quoted_word == NULL)
		return (-1);
	pos = 0;
	if (! (right->children[pos]->type == SY_DOUBLE_QUOTE
			|| right->children[pos]->type == SY_SINGLE_QUOTE))
		return (free(quoted_word), -1);
	pos++;
	while (right->children[pos] != NULL && right->children[pos]->type == SY_ALL)
	{
		all_node = right->children[pos];
		if (ms_replace_joined_str(&quoted_word, all_node->token->token) == NULL)
			return (free(quoted_word), -1);
		pos++;
	}
	free(*left);
	*left = quoted_word;
	return (0);
}
