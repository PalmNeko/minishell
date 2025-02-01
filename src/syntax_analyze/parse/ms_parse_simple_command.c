#include "syntax_analyze.h"
#include "libms.h"
#include <stdlib.h>

static const t_parse_func g_ms_parse_simple_command_func_list[4] = {
	ms_parse_assignment_word,
	ms_parse_redirection_word,
	ms_parse_word_list,
	NULL
};

t_syntax_node *ms_parse_simple_command(t_token **tokens, int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
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
		if(tokens[pos]->type != TK_BLANK || tokens[pos + 1] == NULL)
			break;
		child = ms_parse_symbol_item(tokens, pos + 1, g_ms_parse_simple_command_func_list);
		if (child == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		if(child->type == SY_DECLINED)
		{
			ms_syntax_node_destroy(child);
			break;
		}
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		if(child_lst == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		pos = child->end_pos;
	}
	node = ms_syntax_node_create_nonterminal(SY_SIMPLE_COMMAND, &child_lst, start_pos, pos);
	if(node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	return (node);
}

