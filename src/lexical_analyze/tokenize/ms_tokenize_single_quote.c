/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_single_quote.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:40 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:40 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_single_quote(const char *input, int pos)
{
	t_token	*token;

	input += pos;
	if (ft_includes(input[0], "'"))
		token = ms_create_token(TK_SINGLE_QUOTE, input, pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
