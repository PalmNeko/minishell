#include "syntax_analyze.h"
#include <stdlib.h>

void ms_syntax_node_destroy(t_syntax_node *node)
{
	if (node->children)
	{
		for (int i = 0; node->children[i]; i++)
			ms_syntax_node_destroy(node->children[i]);
		free(node->children);
	}
	free(node);
}
