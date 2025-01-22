/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:01 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:14:02 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "semantic_analyze.h"
#include <stdlib.h>

static t_lsa_command	**_ms_lsa_pipeline(t_syntax_node *pipeline_node);
static t_lsa_pipeline	*ms_create_lsa_pipeline(void);

t_lsa_pipeline	*ms_lsa_pipeline(t_syntax_node *pipeline_node)
{
	t_lsa_pipeline	*lsa_pipeline;
	t_lsa_command	**commands;

	commands = _ms_lsa_pipeline(pipeline_node);
	if (commands == NULL)
		return (NULL);
	lsa_pipeline = ms_create_lsa_pipeline();
	if (lsa_pipeline == NULL)
		return (NULL);
	lsa_pipeline->commands = commands;
	return (lsa_pipeline);
}

static t_lsa_command	**_ms_lsa_pipeline(t_syntax_node *pipeline_node)
{
	t_list			*pipeline_lst;
	t_lsa_command	**commands;
	t_lsa_command	*temp_command;
	size_t			i;

	pipeline_lst = NULL;
	i = 0;
	while (pipeline_node->children[i] != NULL)
	{
		if (pipeline_node->children[i]->type == SY_COMMAND)
		{
			temp_command = ms_lsa_command(pipeline_node->children[i]);
			if (temp_command == NULL)
				return (NULL);
			ms_lstappend_tail(&pipeline_lst, temp_command, NULL);
			if (pipeline_lst == NULL)
				return (NULL);
		}
		i++;
	}
	commands = (t_lsa_command **)ms_lst_to_ntp(&pipeline_lst, ms_identify,
			ms_noop_del);
	if (commands == NULL)
		return (NULL);
	return (commands);
}

static t_lsa_pipeline	*ms_create_lsa_pipeline(void)
{
	t_lsa_pipeline	*lsa_pipeline;

	lsa_pipeline = malloc(sizeof(t_lsa_pipeline));
	if (lsa_pipeline == NULL)
		return (NULL);
	lsa_pipeline->commands = NULL;
	return (lsa_pipeline);
}
