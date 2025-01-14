#include "syntax_analyze.h"

t_syntax_node *ms_parse_redirection_word(t_token **tokens,int pos)
{
	t_syntax_node *node;
	t_syntax_node *child;
	t_syntax_node_list *temp;
	t_syntax_node_list *child_lst;
	const int start_pos = pos;

	child_lst = NULL;
	child = ms_parse_redirection(tokens, pos);
	if (child == NULL)
		return (NULL);
	if(child->token->type != TK_REDIRECTION)
		return(ms_syntax_node_destroy(child), ms_parse_declined(tokens, pos));
	temp = ft_lstnew(child);
	if (temp == NULL)
		return(ms_syntax_node_destroy(child), NULL);
	ft_lstadd_back(&child_lst, temp);
	pos = child->end_pos;
	if(tokens[pos] == NULL)
	{
		ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
		return (ms_parse_declined(tokens, start_pos));
	}
	child = ms_parse_blank(tokens, pos);
	if (child == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	if(child->type == SY_BLANK)
	{
		temp = ft_lstnew(child);
		if (temp == NULL)
			return(ms_syntax_node_destroy(child), ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		ft_lstadd_back(&child_lst, temp);
		pos = child->end_pos;
		if(tokens[pos] == NULL)
		{
			ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper);
			return (ms_parse_declined(tokens, start_pos));
		}
	}
	child = ms_parse_word_list(tokens, pos);
	if (child == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	temp = ft_lstnew(child);
	if (temp == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	ft_lstadd_back(&child_lst, temp);
	node = ms_syntax_node_create(SY_REDIRECTION_WORD);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos + 1;
	return (node);
}
