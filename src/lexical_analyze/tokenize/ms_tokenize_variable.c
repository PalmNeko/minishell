/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:37:39 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:37:43 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_variable(const char *input, int pos)
{
	int		i;
	t_token	*token;

	i = 0;
	input += pos;
	if (ft_includes(input[i++], "$") && ft_includes(input[i++],
			VARIABLE_INITIAL_CHARS))
	{
		while (ft_includes(input[i], IDENTIFY_CHARS))
			i++;
		token = ms_create_token(TK_VARIABLE, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
