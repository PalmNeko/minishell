/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:32:20 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/26 21:32:29 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include <stdlib.h>

char	**ms_expand_commands(t_lsa_word_list **args)
{
	t_list	*itr;
	char	**expanded_args;
	char	**expanded_command;
	size_t	i;
	size_t	j;

	itr = NULL;
	i = 0;
	while (args[i])
	{
		expanded_command = ms_expansion(args[i]);
		if (expanded_command == NULL)
			return (NULL);
		j = 0;
		while (expanded_command[j])
		{
			ms_lstappend_tail(&itr, expanded_command[j], free);
			if (itr == NULL)
				return (NULL);
			j++;
		}
		i++;
	}
	expanded_args = (char **)ms_lst_to_ntp(&itr, ms_identify, ms_noop_del);
	if (expanded_args == NULL)
		return (NULL);
	return (expanded_args);
}
