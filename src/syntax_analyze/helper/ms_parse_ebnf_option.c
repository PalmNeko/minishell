/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_ebnf_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:40:53 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 20:41:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"

int	ms_parse_ebnf_option(t_token **tokens, int pos, t_list **syntax_lst,
		t_parse_func *parsers)
{
	int	end_pos;

	end_pos = pos;
	end_pos = ms_parse_ebnf_one_method(tokens, pos, syntax_lst, parsers);
	if (end_pos == -1)
		return (-1);
	if (end_pos == -2)
		return (pos);
	return (end_pos);
}
