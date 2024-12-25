#include <syntax_analyze.h>
#include <stdlib.h>

t_syntax_node *ms_syntax_node_create(t_syntax_type type, int start_pos, int end_pos)
{
	t_syntax_node	*node;

	node = (t_syntax_node *)malloc(sizeof(t_syntax_node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->children = NULL;
	node->token = NULL;
	node->start_pos = start_pos;
	node->end_pos = end_pos;
	return (node);
}
