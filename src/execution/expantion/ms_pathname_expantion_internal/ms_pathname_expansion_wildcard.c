/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathname_expansion_wildcard.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:33:17 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 08:00:32 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "pathname_expansion_wildcard.h"
#include <stdlib.h>

static char	**ms_get_single_string_list(char *token);

char	**ms_pathname_expansion_wildcard(char *dir_name, char *token)
{
	int		index;
	char	**file_list;
	char	**expanded_path_list;

	file_list = ms_get_file_list_from_dir(dir_name);
	index = 0;
	while (token[index] != '\0')
	{
		if (token[index] == '*')
		{
			expanded_path_list = ms_check_match_wildcard(
					token, index, dir_name, file_list);
			ms_destroy_ntp(file_list);
			return (expanded_path_list);
		}
		index++;
	}
	expanded_path_list = ms_get_single_string_list(token);
	ms_destroy_ntp(file_list);
	return (expanded_path_list);
}

static char	**ms_get_single_string_list(char *token)
{
	char	**expanded_string;

	expanded_string = (char **)malloc(sizeof(char *) * 2);
	if (expanded_string == NULL)
		return (NULL);
	expanded_string[0] = ft_strdup(token);
	if (expanded_string[0] == NULL)
	{
		free(expanded_string);
		return (NULL);
	}
	expanded_string[1] = NULL;
	return (expanded_string);
}
