/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexical_analyze_destory_token.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:37:25 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 20:31:09 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdlib.h>

void	ms_destroy_token(t_token *token)
{
	if (token)
	{
		free((void *)token->token);
		token->token = NULL;
		free(token);
		token = NULL;
	}
}
