#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

void ms_lsa_assignment_destroy(t_lsa_assignment *assignment)
{
	if (assignment == NULL)
		return ;
	if (assignment->name != NULL)
		ms_lsa_wordlist_destroy(assignment->name);
	if (assignment->value != NULL)
		ms_lsa_wordlist_destroy(assignment->value);
	free(assignment);
}
