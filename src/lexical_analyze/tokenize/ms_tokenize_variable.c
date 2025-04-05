/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:37:39 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 12:38:22 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"

t_token	*ms_tokenize_variable(const char *input, int pos)
{
	int		i;
	t_token	*token;

	input += pos;
	i = 0;
	if (ft_includes(input[i++], "$") && ft_includes(input[i++],
			(char *)g_variable_initial_chars))
	{
		while (ft_includes(input[i], (char *)g_identify_chars))
			i++;
		token = ms_create_token(TK_VARIABLE, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
