#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node *ms_parse_pipe(t_token **tokens, int pos)
{
	t_syntax_node *node;

	node = ms_syntax_node_create(SY_PIPE, pos, pos + 1);
	node->token = tokens[pos];
	if (node == NULL)
		return (NULL);
	return (node);
}
