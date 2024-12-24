/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:05 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:07 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
		int end_pos)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = type;
	new_token->token = ft_strndup(token, end_pos - start_pos);
	if (new_token->token == NULL)
		return (ms_lexical_analyze_destroy_token(new_token), NULL);
	new_token->start_pos = start_pos;
	new_token->end_pos = end_pos;
	return (new_token);
}
