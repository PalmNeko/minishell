#include "syntax_analyze.h"
#include "libms.h"
#include <stdlib.h>


static const t_parse_func g_ms_parse_simple_command_func_list[3] = {
	ms_parse_redirection_word,
	ms_parse_word_list,
	NULL
};

t_syntax_node *ms_parse_simple_command(t_token **tokens, int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
	t_syntax_node *child2;
	t_syntax_node_list *child_lst;
	const int start_pos = pos;

	child_lst = NULL;
	child = ms_parse_symbol_item(tokens, pos, g_ms_parse_simple_command_func_list);
	if (child == NULL)
		return (NULL);
	if(child->type == SY_DECLINED)
		return(ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
	if(child_lst == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	pos = child->end_pos;
	while(tokens[pos])
	{
		child = ms_parse_blank(tokens, pos);
		if (child == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		child2 = ms_parse_symbol_item(tokens, child->end_pos, g_ms_parse_simple_command_func_list);
		if (child2 == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), ms_syntax_node_destroy(child), NULL);
		if(child2 != SY_DECLINED)
		{
			ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
			if(child_lst == NULL)
				return(ms_syntax_node_destroy(child), NULL);
			ms_lstappend_tail(&child_lst, child2, ms_syntax_node_destroy_wrapper);
			if(child_lst == NULL)
				return(ms_syntax_node_destroy(child), NULL);
			pos = child2->end_pos;
		}else
			break;
	}
	node = ms_syntax_node_create(SY_SIMPLE_COMMAND);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}

