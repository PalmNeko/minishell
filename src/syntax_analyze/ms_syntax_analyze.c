#include <syntax_analyze.h>

t_syntax_node *ms_syntax_analyze(t_token **tokens)
{
	t_syntax_node *node;

	node = ms_parse_all(tokens, 0);
	// node = ms_parse_instruction(tokens, 0);
	if (node == NULL)
		return (NULL);
	// if (node->type == SY_DECLINED)
	// {
	// 	ms_syntax_node_destroy(node);
	// 	// エラー処理
	// }
	return(node);
}