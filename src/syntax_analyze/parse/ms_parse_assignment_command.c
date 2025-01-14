#include "syntax_analyze.h"

t_syntax_node *ms_parse_assignment_command(t_token **tokens, int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
	t_syntax_node *child2;
	t_syntax_node_list *temp;
	t_syntax_node_list *child_lst;
	const int start_pos = pos;

	child_lst = NULL;
	child = ms_parse_assignment_word(tokens, pos);
	if (child == NULL)
		return (NULL);
	if (child->type == SY_DECLINED)
		return (ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	temp = ft_lstnew(child);
	if (temp == NULL)
		return (ms_syntax_node_destroy(child), NULL);
	ft_lstadd_back(&child_lst, temp);
	pos = child->end_pos;
	while(tokens[pos])
	{
		child = ms_parse_blank(tokens, pos);
		if (child == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		child2 = ms_parse_assignment_word(tokens, child->end_pos);
		if (child2 == NULL)
			return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		if (child2->type != SY_DECLINED)
		{
			temp = ft_lstnew(child);
			if (temp == NULL)
				return (ms_syntax_node_destroy(child), ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
			ft_lstadd_back(&child_lst, temp);
			temp = ft_lstnew(child2);
			if (temp == NULL)
				return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
			ft_lstadd_back(&child_lst, temp);
			pos = child2->end_pos;
		}
		else
			break;
	}
	node = ms_syntax_node_create(SY_ASSIGNMENT_COMMAND);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return (ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos;
	return (node);
}

