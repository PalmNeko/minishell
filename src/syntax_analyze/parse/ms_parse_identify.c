#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node *ms_parse_identify(t_token **tokens, int pos)
{
	t_syntax_node *node;

	if (tokens[pos]->type != TK_IDENTIFY)
		return (ms_parse_declined(tokens, pos));
	node = ms_syntax_node_create(SY_IDENTIFY);
	if (node == NULL)
		return (NULL);
	node->token = tokens[pos];
	node->start_pos = pos;
	node->end_pos = pos + 1;
	return (node);
}
