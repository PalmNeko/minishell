#include "semantic_analyze.h"
#include <stdlib.h>

/* notes
* not yet about heredoc.
*/
t_lsa *semantic_analyze(t_syntax_node *node){
	t_lsa *lsa;
	t_lsa_list **lists;

	lsa = malloc(sizeof(t_lsa));
	if(lsa == NULL)
		return (NULL);
	lists = ms_lsa_lists(node->children[0]);
	if(lists == NULL)
		return (NULL);
	//heredoc用の処理も必要
	lsa->lists = lists;
	return (lsa);
}
