/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:31 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:32 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"

t_token	*ms_tokenize_pipe(const char *input, int pos)
{
	t_token	*token;

	input += pos;
	if (ft_includes(input[0], "|"))
		token = ms_create_token(TK_PIPE, input, pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
