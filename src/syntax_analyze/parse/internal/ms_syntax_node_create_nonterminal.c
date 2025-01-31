#include "syntax_analyze.h"
#include "libms.h"

t_syntax_node	*ms_syntax_node_create_nonterminal(t_syntax_type type, t_list **child_lst, int start_pos, int end_pos)
{
	t_syntax_node	*node;
	t_syntax_node **children;

	children = ms_lst_to_ntp(child_lst, ms_identify, ms_noop_del);
	if (children == NULL)
		return (NULL);
	node = ms_syntax_node_create(type);
	if (node == NULL)
		return (ms_destroy_ntp2((void**)children, ms_syntax_node_destroy_wrapper), NULL);
	node->children = children;
	node->start_pos = start_pos;
	node->end_pos = end_pos;
	return (node);
}
