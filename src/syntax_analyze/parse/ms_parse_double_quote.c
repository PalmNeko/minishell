#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node *ms_parse_double_quote(t_token **tokens, int pos)
{
	t_syntax_node *node;

	node = ms_syntax_node_create(SY_DOUBLE_QUOTE, pos, pos + 1);
	if (node == NULL)
		return (NULL);
	node->token = tokens[pos];
	return (node);
}
