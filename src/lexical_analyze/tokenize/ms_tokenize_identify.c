/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_identify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:18 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 18:13:09 by rnakatan         ###   ########.fr       */
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
		while (ft_includes(input[i], (char *)g_identify_chars))
			i++;
		token = ms_create_token(TK_IDENTIFY, input, pos, pos + i);
	}
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
