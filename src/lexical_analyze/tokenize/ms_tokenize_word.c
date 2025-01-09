/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:45 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:46 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_word(const char *input, int pos)
{
	int		i;
	t_token	*token;

	i = 0;
	input += pos;
	if (!ft_strchr(NOT_WORD_CHARS, input[i]))
	{
		while (!ft_strchr(NOT_WORD_CHARS, input[i]))
			i++;
		token = ms_create_token(TK_WORD, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
