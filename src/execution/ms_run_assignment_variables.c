/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_assignment_variables.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:21:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/08 19:21:42 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>

static char	*ms_expand_assignment_variables(t_lsa_word_list *word_list);

int	ms_run_assignment_variables(t_lsa_assignment **assignments)
{
	int		ret;
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (assignments[i])
	{
		name = ms_expand_assignment_variables(assignments[i]->name);
		if (name == NULL)
			return (-1);
		value = ms_expand_assignment_variables(assignments[i]->value);
		if (value == NULL)
			return (free(name), -1);
		if (ms_getenv(name) == NULL)
			ret = ms_setenv(name, value, 0);
		else
			ret = ms_setenv(name, value, 1);
		if (ret == -1)
			return (-1);
		free(name);
		free(value);
		i++;
	}
	return (ret);
}

static char	*ms_expand_assignment_variables(t_lsa_word_list *word_list)
{
	char	**expanded_texts;
	char	*expanded_text;

	expanded_texts = ms_expansion(word_list);
	if (expanded_texts == NULL)
		return (NULL);
	expanded_text = ms_join_ntp((const char **)expanded_texts, "");
	if (expanded_text == NULL)
		return (NULL);
	ms_destroy_ntp2((void **)expanded_texts, free);
	return (expanded_text);
}
