#include "semantic_analyze.h"
#include "libms.h"

/*
* 下記における<list>の意味解析を担う
* この関数の引数は以下の<list>を想定している
* <instruction> ::= <list> (<newline> <all>*)
* <COMPOUND_LIST> ::= <left_parenthesis> <list> <right_parenthesis>
*/

static t_list *_ms_lsa_lists(t_syntax_node *list_node);
static t_lsa_list_type ms_lsa_list_get_type(t_syntax_node *list_token_node);

t_lsa_list **ms_lsa_lists(t_syntax_node *list_node)
{
	t_list *lists_lst;
	t_lsa_list **lists;

	lists_lst = _ms_lsa_lists(list_node);
	lists = (t_lsa_list **)ms_lst_to_ntp(&lists_lst, ms_identify, ms_noop_del);
	if (lists == NULL)
		return (NULL);
	return (lists);
}

static t_list *_ms_lsa_lists(t_syntax_node *list_node)
{
	t_list *lists_lst;
	t_lsa_list *temp_list;
	int i;

	lists_lst = NULL;
	temp_list = ms_lsa_list(list_node->children[0]);
	if (temp_list == NULL)
		return (NULL);
	ms_lstappend_tail(&lists_lst, temp_list, NULL);
	if (lists_lst == NULL)
		return (NULL);
	i = 1;
	while (list_node->children[i] != NULL)
	{
		temp_list = ms_lsa_list(list_node->children[i + 1]);
		if (temp_list == NULL)
			return (NULL);
		temp_list->type = ms_lsa_list_get_type(list_node->children[i]);
		ms_lstappend_tail(&lists_lst, temp_list, NULL);
		if (lists_lst == NULL)
			return (NULL);
		i+=2;
	}
	return (lists_lst);
}

static t_lsa_list_type ms_lsa_list_get_type(t_syntax_node *list_token_node)
{
	const char *token = list_token_node->token->token;
	if (ft_strcmp(token, "||") == 0)
		return (LSA_LIST_OR);
	else if (ft_strcmp(token, "&&") == 0)
		return (LSA_LIST_AND);
	return (LSA_LIST_ALWAYS);
}
