#include "semantic_analyze.h"
#include "syntax_analyze.h"
#include "libms.h"
#include "lexer.h"
#include "execution.h"
#include <stdlib.h>

int ms_execution(const char *input)
{
	t_token **tokens;
	t_syntax_node *node;
	t_lsa *lsa;
	int ret;

	tokens = ms_lexical_analyze(input);
	node = ms_syntax_analyze(tokens);
	lsa = semantic_analyze(node);
	ret = ms_execute_from_lsa(lsa);
	// free of lsa
	ms_syntax_node_destroy(node);
	ms_destroy_ntp2((void **)tokens, free);
	return (ret);
}
