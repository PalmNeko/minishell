/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 06:27:13 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

bool ms_is_word_token_char(const char *str);

t_token	*ms_tokenize_word(const char *input, int pos)
{
	const int start_pos = pos;
	t_token	*token;

	if (ms_is_word_token_char(&input[pos]))
	{
		while (input[pos] && ms_is_word_token_char(&input[pos]))
			pos++;
		token = ms_create_token(TK_WORD, input, start_pos, pos);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}

bool ms_is_word_token_char(const char *str)
{
	if (ft_includes(*str, NOT_WORD_CHARS))
	{
		if(*str == '&' && ft_strncmp(str, "&&", 2) == 0)
			return (0);
	}
	return (1);
}