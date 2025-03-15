/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_duplicate_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:07:13 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 22:07:18 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"
#include <stdlib.h>

t_token	*ms_duplicate_token(t_token *token)
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
