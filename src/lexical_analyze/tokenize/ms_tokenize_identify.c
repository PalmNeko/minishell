/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_identify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:18 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:39:20 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
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

// #include <stdio.h>

// int	main(void)
// {
// 	t_token *token;

// 	token = ms_tokenize_identify("_test", 0);
// 	printf("token->type: %d\n", token->type);
// 	printf("token->token: %s\n", token->token);
// 	printf("token->start_pos: %d\n", token->start_pos);
// 	if (token->type != TK_IDENTIFY)
// 		return (1);
// 	if (token->start_pos != 0)
// 		return (1);
// 	if (token->end_pos != 3)
// 		return (1);
// 	return (0);
// }