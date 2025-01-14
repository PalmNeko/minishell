#include "semantic_analyze.h"
#include <stdlib.h>

t_lsa *semantic_analyze(t_syntax_node *node){
	(void)node;
	t_lsa *lsa = malloc(sizeof(t_lsa));
	if (lsa == NULL)
		return (NULL);
	lsa->lists = NULL;
	return (lsa);
}