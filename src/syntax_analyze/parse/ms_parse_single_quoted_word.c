// #include "syntax_analyze.h"
// #include <stdlib.h>

// static t_syntax_node **ms_parse_create_single_quoted_word_children(t_token **token, int start_pos, int end_pos);

// t_syntax_node *ms_parse_single_quoted_word(t_token **tokens, int pos)
// {
// 	t_syntax_node *node;
// 	t_syntax_node **children;
// 	const int start_pos = pos;

// 	pos++;
// 	while (tokens[pos] && tokens[pos]->type != TK_SINGLE_QUOTE)
// 		pos++;
// 	pos++;
// 	node = ms_syntax_node_create(SY_SINGLE_QUOTED_WORD, start_pos, pos);
// 	if (node == NULL)
// 		return (NULL);
// 	children = ms_parse_create_single_quoted_word_children(tokens, start_pos, pos);
// 	if (children == NULL)
// 	{
// 		ms_syntax_node_destroy(node);
// 		return (NULL);
// 	}
// 	node->children = children;
// 	return (node);
// }

// static t_syntax_node **ms_parse_create_single_quoted_word_children(t_token **tokens, int start_pos, int end_pos)
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
// 			children[i] = ms_parse_single_quote(tokens, pos);
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