#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include "libms.h"
#include <stdlib.h>

static void ms_lsa_command_destroy_wrapper(void *command);

void ms_lsa_pipeline_destroy(t_lsa_pipeline *pipeline)
{
	if (pipeline == NULL)
		return ;
	if (pipeline->commands != NULL)
		ms_destroy_ntp2((void **)pipeline->commands, ms_lsa_command_destroy_wrapper);
	free(pipeline);
}

void ms_lsa_command_destroy_wrapper(void *command)
{
	ms_lsa_command_destroy((t_lsa_command *)command);
}
