#include "semantic_analyze.h"
#include <stdlib.h>

t_lsa_word_list *ms_lsa_word_list(t_syntax_node *wordlist_node)
{
	t_lsa_word_list *lsa_wordlist;

	lsa_wordlist = (t_lsa_word_list *)malloc(sizeof(t_lsa_word_list));
	if (lsa_wordlist == NULL)
		return (NULL);
	lsa_wordlist->word_list = wordlist_node;
	return (lsa_wordlist);
}
