#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node *ms_parse_double_quoted_word(t_token **tokens, int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
	t_syntax_node_list *temp;
	t_syntax_node_list *child_lst;
	const int start_pos = pos;

	child_lst = NULL;
	child = ms_parse_double_quote(tokens, pos);
	if (child == NULL)
		return (NULL);
	if(child->token->type != TK_DOUBLE_QUOTE)
	{
		ms_syntax_node_destroy(child);
		return (ms_parse_declined(tokens, pos));
	}
	temp = ft_lstnew(child);
	if (temp == NULL)
		return(ms_syntax_node_destroy(child), NULL);
	ft_lstadd_back(&child_lst, temp);
	pos++;
	while(tokens[pos])
	{
		if(tokens[pos]->type == TK_DOUBLE_QUOTE)
			break;
		child = ms_parse_all(tokens, pos);
		if (child == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		temp = ft_lstnew(child);
		if (temp == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		ft_lstadd_back(&child_lst, temp);
		pos++;
	}
	if(tokens[pos] == NULL)
	{
		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		return (ms_parse_declined(tokens, start_pos));
	}
	child = ms_parse_double_quote(tokens, pos);
	if (child == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	temp = ft_lstnew(child);
	if (temp == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	ft_lstadd_back(&child_lst, temp);
	node = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos + 1;
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
// // 			break;
// // 		if (str[0] == '\0')
// // 		{
// // 			free(str);
// // 			break;
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
// // 			continue;
// // 		}else{
// // 		for(int i = 0; node->children[i]; i++)
// // 		{
// // 			int str_len = node->children[i]->token->end_pos - node->children[i]->token->start_pos;
// // 			printf("node->children[%d]->token->token: %s\n", i, node->children[i]->token->token);
// // 		}
// // 		ms_syntax_node_destroy(node);
// // 		// ms_lexical_analyze_destroy_token(tokens[0]);
// // 		free(tokens);
// // 		free(str);
// // 		}
// // 	}
// // 	return (0);
// // }