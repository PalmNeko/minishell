/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:20 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 21:11:07 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>

static void	_ms_expand_commands(char **expanded_command, t_list **expand_itr);

char	**ms_expand_commands(t_lsa_word_list **args)
{
	t_list	*expand_itr;
	char	**expanded_args;
	char	**expanded_command;
	size_t	i;

	expand_itr = NULL;
	i = 0;
	while (args[i])
	{
		expanded_command = ms_expansion(args[i]);
		if (expanded_command == NULL)
			return (NULL);
		_ms_expand_commands(expanded_command, &expand_itr);
		if (expand_itr == NULL)
			return (NULL);
		free(expanded_command);
		i++;
	}
	expanded_args = (char **)ms_lst_to_ntp(&expand_itr, ms_identify,
			ms_noop_del);
	if (expanded_args == NULL)
		return (NULL);
	return (expanded_args);
}

static void	_ms_expand_commands(char **expanded_command, t_list **expand_itr)
{
	size_t	j;

	j = 0;
	while (expanded_command[j])
	{
		ms_lstappend_tail(expand_itr, expanded_command[j], free);
		if (expand_itr == NULL)
			return ;
		j++;
	}
}
