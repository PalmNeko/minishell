/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize_equal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:38:15 by rnakatan          #+#    #+#             */
/*   Updated: 2024/12/25 07:38:16 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"

t_token	*ms_tokenize_equal(const char *input, int pos)
{
	t_token	*token;

	input += pos;
	if (ft_includes(input[0], "="))
		token = ms_create_token(TK_EQUALS, input, pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
