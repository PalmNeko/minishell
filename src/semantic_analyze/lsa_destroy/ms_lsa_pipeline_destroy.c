/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_pipeline_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:12:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:13:03 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

static void	ms_lsa_command_destroy_wrapper(void *command);

void	ms_lsa_pipeline_destroy(t_lsa_pipeline *pipeline)
{
	if (pipeline == NULL)
		return ;
	if (pipeline->commands != NULL)
		ms_destroy_ntp2((void **)pipeline->commands,
			ms_lsa_command_destroy_wrapper);
	free(pipeline);
}

void	ms_lsa_command_destroy_wrapper(void *command)
{
	ms_lsa_command_destroy((t_lsa_command *)command);
}
