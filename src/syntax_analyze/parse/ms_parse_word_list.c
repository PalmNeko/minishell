
#include "syntax_analyze.h"
#include <stdlib.h>

static const t_parse_func	g_ms_parse_wordlist_func_list[5] = {
	ms_parse_identify, 
	ms_parse_word, 
	ms_parse_single_quoted_word,
	ms_parse_double_quoted_word, 
	NULL
};

static t_syntax_node *ms_parse_worditem(t_token **tokens, int pos);	

t_syntax_node *ms_parse_word_list(t_token **tokens, int pos)
{
	t_syntax_node_list *child_lst;
	t_syntax_node_list *temp;
	t_syntax_node *child;
	t_syntax_node *node;
	const int start_pos = pos;

	child_lst = NULL;
	child = ms_parse_worditem(tokens, pos);
	if (child == NULL)
		return (NULL);
	if(child->type == SY_DECLINED)
		return(ms_syntax_node_destroy(child),ms_parse_declined(tokens, pos));
	temp = ft_lstnew(child);
	if (temp == NULL)
		return(ms_syntax_node_destroy(child), NULL);
	ft_lstadd_back(&child_lst, temp);
	pos = child->end_pos;
	while(tokens[pos] && child->type != SY_DECLINED)
	{
		child = ms_parse_worditem(tokens, pos);
		if (child == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		if(child->type == SY_DECLINED)
			break;
		temp = ft_lstnew(child);
		if (temp == NULL)
			return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
		ft_lstadd_back(&child_lst, temp);
		pos = child->end_pos;
	}
	if(tokens[pos] == NULL)
		pos--;
	node = ms_syntax_node_create(SY_WORD_LIST);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node = ms_syntax_node_set_of_children(node, &child_lst);
	if (node == NULL)
		return(ft_lstclear(&child_lst, ms_syntax_node_destroy_wrapper), NULL);
	node->start_pos = start_pos;
	node->end_pos = pos + 1;
	return (node);
}

static t_syntax_node *ms_parse_worditem(t_token **tokens, int pos)
{
	t_syntax_node *node;
	int i;

	i = 0;
	while(g_ms_parse_wordlist_func_list[i])
	{
		node = g_ms_parse_wordlist_func_list[i](tokens, pos);
		if(node == NULL)
			return (NULL);
		if(node->type != SY_DECLINED)
			return (node);
		i++;
		free(node);
	}
	return (ms_parse_declined(tokens, pos));
}
