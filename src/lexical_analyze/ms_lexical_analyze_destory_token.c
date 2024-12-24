/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexical_analyze_destory_token.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:37:25 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:39:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdlib.h>

void	ms_lexical_analyze_destroy_token(t_token *token)
{
	if (token)
	{
		free((void *)token->token);
		free(token);
	}
}
