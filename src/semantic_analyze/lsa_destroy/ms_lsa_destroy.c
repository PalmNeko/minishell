#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

void ms_lsa_destroy(t_lsa *lsa)
{
	int i;

	if (lsa == NULL)
		return ;
	i = 0;
	while (lsa->lists[i] != NULL)
	{
		ms_lsa_list_destroy(lsa->lists[i]);
		i++;
	}
	free(lsa->lists);
	free(lsa);
}