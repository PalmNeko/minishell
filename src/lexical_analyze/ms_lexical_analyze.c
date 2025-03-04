/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexical_analyze.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:26:37 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 21:34:34 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"
#include "libft.h"
#include "libms.h"
#include <stdlib.h>

static const t_tokenize_func	g_ms_tokenize_func_list[14] = {
	ms_tokenize_word,
	ms_tokenize_identify,
	ms_tokenize_right_parenthesis,
	ms_tokenize_left_parenthesis,
	ms_tokenize_newline,
	ms_tokenize_equal,
	ms_tokenize_double_quote,
	ms_tokenize_single_quote,
	ms_tokenize_redirection,
	ms_tokenize_blank,
	ms_tokenize_pipe,
	ms_tokenize_list,
	ms_tokenize_variable,
	NULL
};

static t_token					*get_token(const char *input, int pos);
static int						compare_priority(t_token *temp_token,
									t_token *token);

/*
  TK_DECLINEだった時の処理のロジックが甘い？(今回の場合TK_DECLINEは存在しないけど)
*/
t_token	**ms_lexical_analyze(const char *input)
{
	t_token_list	*lst;
	t_token_list	*new_lst;
	t_token			**tokens;
	t_token			*token;
	size_t			pos;

	lst = NULL;
	pos = 0;
	while (ft_includes(input[pos], " \t"))
		pos++;
	while (input[pos])
	{
		token = get_token(input, pos);
		if (!token)
			return (NULL);
		if (token->type == TK_DECLINED)
		{
			ms_destroy_token(token);
			return (NULL);
		}
		new_lst = ft_lstnew(token);
		if (!new_lst)
			return (NULL);
		ft_lstadd_back(&lst, new_lst);
		pos = token->end_pos;
	}
	tokens = ms_lst_to_ntp(&lst, ms_identify, ms_noop_del);
	if (!tokens)
	{
		ft_lstclear(&lst, ms_destroy_token_wrapper);
		return (NULL);
	}
	return (tokens);
}

static t_token	*get_token(const char *input, int pos)
{
	t_token	*token;
	t_token	*temp_token;
	size_t	i;

	token = NULL;
	i = 0;
	while (g_ms_tokenize_func_list[i])
	{
		temp_token = g_ms_tokenize_func_list[i](input, pos);
		if (compare_priority(temp_token, token))
		{
			if (token)
				ms_destroy_token(token);
			token = temp_token;
		}
		else
			ms_destroy_token(temp_token);
		i++;
	}
	return (token);
}

static int	compare_priority(t_token *temp_token, t_token *token)
{
	size_t	temp_token_len;
	size_t	token_len;

	if (temp_token && !token)
		return (1);
	temp_token_len = temp_token->end_pos - temp_token->start_pos;
	token_len = token->end_pos - token->start_pos;
	if ((temp_token->type > 2 && token->type > 2) || (temp_token->type <= 2
			&& token->type <= 2))
	{
		if (temp_token_len >= token_len)
			return (1);
		else
			return (0);
	}
	if (temp_token->type > token->type)
		return (1);
	return (0);
}
