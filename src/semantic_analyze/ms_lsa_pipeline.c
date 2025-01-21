#include "semantic_analyze.h"
#include "libms.h"
#include <stdlib.h>

static t_lsa_pipeline *ms_create_lsa_pipeline(void);

t_lsa_pipeline *ms_lsa_pipeline(t_syntax_node *pipeline_node)
{
	t_lsa_pipeline *lsa_pipeline;
	t_list *pipeline_lst;
	t_lsa_command *temp_command;
	size_t i;

	pipeline_lst = NULL;
	i = 0;
	while (pipeline_node->children[i] != NULL)
	{
		if(pipeline_node->children[i]->type == SY_COMMAND)
		{
			temp_command = ms_lsa_command(pipeline_node->children[i]);
			if (temp_command == NULL)
				return (NULL);
			ms_lstappend_tail(&pipeline_lst, temp_command, NULL);
			if (pipeline_lst == NULL)
				return (NULL);
			i++;
		}
	}
	lsa_pipeline = ms_create_lsa_pipeline();
	if (lsa_pipeline == NULL)
		return (NULL);
	lsa_pipeline->commands = (t_lsa_command **)ms_lst_to_ntp(&pipeline_lst, ms_identify, ms_noop_del);
	if (lsa_pipeline->commands == NULL)
		return (NULL);
	return (lsa_pipeline);
}

static t_lsa_pipeline *ms_create_lsa_pipeline(void)
{
	t_lsa_pipeline *lsa_pipeline;

	lsa_pipeline = malloc(sizeof(t_lsa_pipeline));
	if (lsa_pipeline == NULL)
		return (NULL);
	lsa_pipeline->commands = NULL;
	return (lsa_pipeline);
}
