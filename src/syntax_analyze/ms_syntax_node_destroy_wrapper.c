#include "syntax_analyze.h"

void ms_syntax_node_destroy_wrapper(void *node)
{
	t_syntax_node *syntax_node;

	syntax_node = (t_syntax_node *)node;
	ms_syntax_node_destroy(syntax_node);
}

