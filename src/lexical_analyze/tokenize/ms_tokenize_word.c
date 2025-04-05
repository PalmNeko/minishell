/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:45 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 12:40:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"

static bool	ms_is_word_token_char(const char *str);
static bool	ms_is_word_token_char_special(const char *str);

t_token	*ms_tokenize_word(const char *input, int pos)
{
	const int	start_pos = pos;
	t_token		*token;

	if (input[pos] && ms_is_word_token_char(&input[pos]))
	{
		while (input[pos] && ms_is_word_token_char(&input[pos]))
			pos++;
		token = ms_create_token(TK_WORD, &input[start_pos], start_pos, pos);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}

bool	ms_is_word_token_char(const char *str)
{
	if (ft_includes(*str, NOT_WORD_CHARS))
	{
		return (ms_is_word_token_char_special(str));
	}
	return (true);
}

bool	ms_is_word_token_char_special(const char *str)
{
	if (*str == '&' && ft_strncmp(str, "&&", 2) != 0)
		return (true);
	if (str[0] == '$'
		&& (str[1] == '\0'
			|| !ft_includes(str[1], (char *)g_variable_initial_chars)))
		return (true);
	return (false);
}
