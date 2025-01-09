// #include "syntax_analyze.h"
// #include <stdlib.h>

// static const t_token_type g_word_list_types[5] = {
// 	TK_WORD,
// 	TK_SINGLE_QUOTE,
// 	TK_DOUBLE_QUOTE,
// 	TK_VARIABLE,
// 	TK_IDENTIFY,
// };

// static const t_parse_func g_parse_funcs[6] = {
// 	ms_parse_word,
// 	ms_parse_single_quoted_word,
// 	ms_parse_double_quoted_word,
// 	ms_parse_variable,
// 	ms_parse_identify,
// 	NULL
// };

// static t_syntax_node **ms_parse_create_word_list_children(t_token **tokens, int *pos);
// static void **convert_to_array(t_token_list *lst);

// t_syntax_node *ms_parse_word_list(t_token **tokens, int pos)
// {
// 	t_syntax_node *node;
// 	t_syntax_node **children;

// 	node = ms_syntax_node_create(SY_WORD_LIST, pos, pos);
// 	if (node == NULL)
// 		return (NULL);
// 	children = ms_parse_create_word_list_children(tokens, &pos);
// 	if (children == NULL)
// 	{
// 		ms_syntax_node_destroy(node);
// 		return (NULL);
// 	}
// 	node->children = children;
// 	node->end_pos = pos;
// 	return (node);
// }

// #include <stdio.h>

// static t_syntax_node **ms_parse_create_word_list_children(t_token **tokens, int *pos)
// {
// 	t_syntax_node **children;
// 	t_syntax_node *child;
// 	t_syntax_node_list *new_lst;
// 	t_syntax_node_list *lst;
// 	int i;

// 	lst = NULL;
// 	while (tokens[*pos])
// 	{
// 		i = 0;
// 		while (g_parse_funcs[i] && g_word_list_types[i] != tokens[*pos]->type)
// 			i++;
// 		if (g_parse_funcs[i] == NULL)
// 			break;
// 		child = g_parse_funcs[i](tokens, *pos);
// 		if (child == NULL)
// 			return (NULL);
// 		new_lst = ft_lstnew(child);
// 		if (new_lst == NULL)
// 			return (NULL);
// 		ft_lstadd_back(&lst, new_lst);
// 		printf("child->end_pos - child->start_pos: %d\n", child->end_pos - child->start_pos);
// 		*pos += (child->end_pos - child->start_pos);
// 	}
// 	children = (t_syntax_node **)convert_to_array(lst);
// 	if (children == NULL)
// 	{
// 		while (lst)
// 		{
// 			new_lst = lst;
// 			lst = lst->next;
// 			free(new_lst);
// 		}
// 		return (NULL);
// 	}
// 	return (children);
// }

// static void	**convert_to_array(t_token_list *lst)
// {
// 	t_list	*temp;
// 	void			**contents;
// 	size_t			size;
// 	size_t			i;

// 	size = ft_lstsize(lst);
// 	contents = (void **)malloc(sizeof(void *) * (size + 1));
// 	if (!contents)
// 		return (NULL);
// 	i = 0;
// 	while (lst)
// 	{
// 		temp = lst;
// 		contents[i] = lst->content;
// 		lst = lst->next;
// 		free(temp);
// 		i++;
// 	}
// 	contents[i] = NULL;
// 	return (contents);
// }

