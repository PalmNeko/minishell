#include <syntax_analyze.h>

#include <stdio.h>

t_syntax_node *ms_syntax_analyze(t_token **tokens)
{
	t_syntax_node *node;

	node = ms_parse_instruction(tokens, 0);
	if (node == NULL)
		return (NULL);
	if (node->type == SY_DECLINED)
		printf("error at %d\n", node->start_pos);
	return(node);
}