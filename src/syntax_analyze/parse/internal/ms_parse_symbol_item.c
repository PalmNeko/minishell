#include "syntax_analyze.h"


#include <stdio.h>
t_syntax_node *ms_parse_symbol_item(t_token **tokens,int pos, const t_parse_func *func_list)
{
	t_syntax_node *node;
	int i;

	i = 0;
	while(func_list[i]){
		node = func_list[i](tokens, pos);
		if(node == NULL)
			return (NULL);
		if(node->type != SY_DECLINED)
			return (node);
		ms_syntax_node_destroy(node);
		i++;
	}
	return (ms_parse_declined(tokens, pos));
}
