/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_ebnf_repeat_method.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:38:26 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 20:42:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include "syntax_analyze.h"

int	ms_parse_ebnf_repeat_method(t_token **tokens, int pos, t_list **syntax_lst,
		t_parse_func *parsers)
{
	t_list	*working_lst;
	int		end_pos;
	int		new_pos;

	working_lst = NULL;
	end_pos = pos;
	while (1)
	{
		new_pos = ms_parse_ebnf_one_method(tokens, end_pos, &working_lst,
				parsers);
		if (new_pos == -1)
			return (ft_lstclear(&working_lst, ms_syntax_node_destroy_wrapper),
				-1);
		else if (new_pos == -2)
			break ;
		end_pos = new_pos;
	}
	*syntax_lst = working_lst;
	return (end_pos);
}
