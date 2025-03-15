/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_match_wildcard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:48:00 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 08:22:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "pathname_expansion_wildcard.h"
#include <stdlib.h>

static t_search_string	*ms_get_search_strings(
							char *token_string, int index, char *dir_name);
static int				ms_compare_after_strings(char *file_name,
							char **after_string, t_list **match_path_lst);
static void				ms_destroy_search_string(
							t_search_string *search_string);

char	**ms_check_match_wildcard(char *token_string, int index,
				char *dir_name, char **file_list)
{
	t_list			*match_path_lst;
	char			**match_path_list;
	int				i;
	t_search_string	*search_string;

	search_string = ms_get_search_strings(token_string, index, dir_name);
	if (search_string == NULL)
		return (NULL);
	match_path_lst = NULL;
	i = 0;
	while (file_list[i] != NULL)
	{
		if (ft_strncmp(file_list[i], search_string->before, index) == 0)
		{
			if (ms_compare_after_strings(file_list[i],
					search_string->after, &match_path_lst) == -1)
				return (NULL);
		}
		i++;
	}
	match_path_list = ms_lst_to_ntp(&match_path_lst, ms_identify, ms_noop_del);
	ms_destroy_search_string(search_string);
	return (match_path_list);
}

static void	ms_destroy_search_string(t_search_string *search_string)
{
	if (search_string == NULL)
		return ;
	free(search_string->before);
	ms_destroy_ntp(search_string->after);
	free(search_string);
}

static t_search_string	*ms_get_search_strings(
							char *token_string, int index, char *dir_name)
{
	t_search_string	*search_string;

	search_string = (t_search_string *)malloc(sizeof(t_search_string));
	if (search_string == NULL)
		return (NULL);
	search_string->before = ft_strndup(token_string, index);
	if (search_string->before == NULL)
	{
		ms_destroy_search_string(search_string);
		return (NULL);
	}
	token_string += index + 1;
	search_string->after = ms_pathname_expansion_wildcard(
			dir_name, token_string);
	if (search_string->after == NULL)
	{
		ms_destroy_search_string(search_string);
		return (NULL);
	}
	return (search_string);
}

static int	ms_compare_after_strings(char *file_name, char **after_strings,
				t_list **match_path_lst)
{
	int	i;

	i = 0;
	while (after_strings[i] != NULL)
	{
		if (ft_strcmp(file_name + ft_strlen(file_name)
				- ft_strlen(after_strings[i]), after_strings[i]) == 0)
		{
			if (ms_add_string_to_lst(match_path_lst, file_name) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}
