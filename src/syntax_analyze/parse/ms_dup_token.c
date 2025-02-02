/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dup_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:32:26 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:32:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "syntax_analyze.h"
#include <stdlib.h>

t_token	*ms_dup_token(t_token *token)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = token->type;
	new_token->token = ft_strdup(token->token);
	if (new_token->token == NULL)
	{
		free(new_token);
		return (NULL);
	}
	new_token->start_pos = token->start_pos;
	new_token->end_pos = token->end_pos;
	return (new_token);
}
