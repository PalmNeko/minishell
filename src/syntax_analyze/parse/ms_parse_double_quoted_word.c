/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_double_quoted_word.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:33:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 18:05:49 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node	*ms_parse_double_quoted_word(t_token **tokens, int pos)
{
	t_syntax_node		*node;
	t_syntax_node		*child;
	t_syntax_node_list	*child_lst;
	const int			start_pos = pos;

	child_lst = NULL;
	child = ms_parse_double_quote(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->token->type != TK_DOUBLE_QUOTE)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	pos = child->end_pos;
	while (tokens[pos])
	{
		if (tokens[pos]->type == TK_DOUBLE_QUOTE)
			break ;
		child = ms_parse_all(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper),
				NULL);
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if (child_lst == NULL)
			return (ms_syntax_node_destroy(child), NULL);
		pos = child->end_pos;
	}
	if (tokens[pos] == NULL)
	{
		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		return (ms_parse_declined(tokens, start_pos));
	}
	child = ms_parse_double_quote(tokens, pos);
	if (child == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if (child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	node = ms_syntax_node_create_nonterminal(SY_DOUBLE_QUOTED_WORD, &child_lst, start_pos, pos);
	return (node);
}

// // #include <stdio.h>
// // #include <readline/readline.h>
// // int main(void)
// // {
// // 	char *str = NULL;
// // 	while(1)
// // 	{
// // 		str = readline("input: ");
// // 		if (!str)
// // 			break ;
// // 		if (str[0] == '\0')
// // 		{
// // 			free(str);
// // 			break ;
// // 		}
// // 		t_token **tokens = ms_lexical_analyze(str);
// // 		t_syntax_node *node = ms_parse_double_quoted_word(tokens, 0);
// // 		if(node->type == SY_DECLINED)
// // 		{
// // 			printf("node->type: %d\n", node->type);
// // 			printf("node->token->token: %s\n", node->token->token);
// // 			ms_syntax_node_destroy(node);
// // 			free(tokens);
// // 			free(str);
// // 			continue ;
// // 		}else{
// // 		for(int i = 0; node->children[i]; i++)
// // 		{
// // 			int str_len = node->children[i]->token->end_pos
// - node->children[i]->token->start_pos;
// // 			printf("node->children[%d]->token->token: %s\n", i,
// node->children[i]->token->token);
// // 		}
// // 		ms_syntax_node_destroy(node);
// // 		// ms_lexical_analyze_destroy_token(tokens[0]);
// // 		free(tokens);
// // 		free(str);
// // 		}
// // 	}
// // 	return (0);
// // }