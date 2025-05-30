/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:35 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:36 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"

t_token	*ms_tokenize_redirection(const char *input, int pos)
{
	t_token	*token;

	input += pos;
	if (ft_strncmp(input, "<<", 2) == 0 || ft_strncmp(input, ">>", 2) == 0)
		token = ms_create_token(TK_REDIRECTION, input, pos, pos + 2);
	else if (ft_includes(input[0], "<") || ft_includes(input[0], ">"))
		token = ms_create_token(TK_REDIRECTION, input, pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
