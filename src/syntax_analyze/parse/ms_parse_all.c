#include "syntax_analyze.h"
#include <stdlib.h>

t_syntax_node *ms_parse_all(t_token *token, int pos)
{
	t_syntax_node *node;

	(void)token;
	node = ms_syntax_node_create(SY_ALL, pos, pos + 1);
	if (node == NULL)
		return (NULL);
	return (node);
}
