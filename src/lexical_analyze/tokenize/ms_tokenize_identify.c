/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_identify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:18 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/28 18:19:52 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

t_token	*ms_tokenize_identify(const char *input, int pos)
{
	int		i;
	t_token	*token;

	input += pos;
	i = 0;
	if (ft_includes(input[i], LETTER_CHARS))
	{
		i++;
		while (ft_includes(input[i], IDENTIFY_CHARS))
			i++;
		token = ms_create_token(TK_IDENTIFY, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
