/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_blank.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:09 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:10 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"
#include <stdlib.h>

t_token	*ms_tokenize_blank(const char *input, int pos)
{
	int		i;
	t_token	*token;

	i = 0;
	input += pos;
	if (ft_includes(input[i], BLANK_CHARS))
	{
		i++;
		while (ft_includes(input[i], BLANK_CHARS))
			i++;
		token = ms_create_token(TK_BLANK, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
