#include "semantic_analyze.h"
#include <stdlib.h>

void	ms_lsa_wordlist_destroy(t_lsa_word_list *wordlist)
{
	if (wordlist == NULL)
		return ;
	free(wordlist);
}
