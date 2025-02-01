#include "syntax_analyze.h"
int ms_syntax_node_check_declined(t_syntax_node *node)
{
	if (node->type == SY_DECLINED)
	{
		ms_syntax_node_destroy(node);
		return (1);
	}
	return (0);
}