// #include "syntax_analyze.h"
// #include <stdlib.h>

// static t_syntax_node **ms_parse_create_double_quoted_word_children(t_token **token, int start_pos, int end_pos);

// t_syntax_node *ms_parse_double_quoted_word(t_token **tokens, int pos)
// {
// 	t_syntax_node *node;
// 	t_syntax_node **children;
// 	const int start_pos = pos;

// 	pos++;
// 	while (tokens[pos] && tokens[pos]->type != TK_DOUBLE_QUOTE)
// 		pos++;
// 	pos++;
// 	node = ms_syntax_node_create(SY_DOUBLE_QUOTED_WORD, start_pos, pos);
// 	if (node == NULL)
// 		return (NULL);
// 	children = ms_parse_create_double_quoted_word_children(tokens, start_pos, pos);
// 	if (children == NULL)
// 	{
// 		ms_syntax_node_destroy(node);
// 		return (NULL);
// 	}
// 	node->children = children;
// 	return (node);
// }

// static t_syntax_node **ms_parse_create_double_quoted_word_children(t_token **tokens, int start_pos, int end_pos)
// {
// 	t_syntax_node **children;
// 	int i;
// 	int pos;

// 	children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * (end_pos - start_pos + 1));
// 	if (children == NULL)
// 		return (NULL);
// 	i = 0;
// 	pos = start_pos;
// 	while (pos < end_pos)
// 	{
// 		if(i > 0 && i < end_pos - start_pos - 1)
// 			children[i] = ms_parse_all(tokens, pos);
// 		else if(tokens[pos])
// 			children[i] = ms_parse_double_quote(tokens, pos);
// 		else
// 			children[i] = ms_parse_decliend(tokens, pos - 1);
// 		if (children[i] == NULL)
// 		{
// 			while (--i >= 0)
// 				ms_syntax_node_destroy(children[i]);
// 			free(children);
// 			return (NULL);
// 		}
// 		i++;
// 		pos++;
// 	}
// 	children[i] = NULL;
// 	return (children);
// }

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