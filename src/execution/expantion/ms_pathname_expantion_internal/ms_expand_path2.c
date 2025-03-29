/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_path2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:44:22 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/29 15:41:44 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include "pathname_expansion_wildcard.h"
#include <stdlib.h>

static char		**ms_sep_dir_token(char *token);
static char		***ms_get_expanded_tokens_list(char **dir_list);
static char		**ms_get_expanded_token(char ***expanded_tokens_list);

char	*ms_expand_path2(char *token)
{
	char			***expanded_tokens_list;
	char			*expanded_string;
	char			**expanded_token_list;
	char			**sep_token_list;

	sep_token_list = ms_sep_dir_token(token);
	if (sep_token_list == NULL)
		return (NULL);
	expanded_tokens_list = ms_get_expanded_tokens_list(sep_token_list);
	ms_destroy_ntp(sep_token_list);
	if (expanded_tokens_list == NULL)
		return (NULL);
	expanded_token_list = ms_get_expanded_token(expanded_tokens_list);
	ms_destroy_ntp2((void **)expanded_tokens_list,free);
	if (expanded_token_list == NULL)
		return (NULL);
	expanded_string = ms_join_ntp((const char **)expanded_token_list, " ");
	ms_destroy_ntp(expanded_token_list);
	if (expanded_string == NULL)
		return (NULL);
	return (expanded_string);
}

static char	**ms_sep_dir_token(char *token)
{
	char	**dir_list;
	char	*token_string;
	int		i;

	token_string = ft_strdup(token);
	if (ft_strncmp(token, "./", 2) != 0 && ft_strncmp(token, "/", 1) != 0
		&& ms_replace_joined_str_right("./", &token_string) == NULL)
		return (NULL);
	dir_list = ft_split(token_string, '/');
	if (dir_list == NULL)
		return (NULL);
	if (token[0] == '/' && ms_replace_joined_str(&dir_list[0], "/") == NULL)
		return (ms_destroy_ntp(dir_list), NULL);
	i = 1;
	while (dir_list[i] != NULL && dir_list[i + 1] != NULL)
	{
		if (ms_replace_joined_str(&dir_list[i], "/") == NULL)
			return (ms_destroy_ntp(dir_list), NULL);
		i++;
	}
	free(token_string);
	return (dir_list);
}

static char	***ms_get_expanded_tokens_list(char **token_list)
{
	int				i;
	t_list			*expanded_token_lst;
	char			**expanded_token_list;

	expanded_token_lst = NULL;
	i = 0;
	while (token_list[i] != NULL && token_list[i + 1] != NULL)
	{
		expanded_token_list = ms_pathname_expansion_wildcard(
				token_list[i], token_list[i + 1]);
		if (expanded_token_list == NULL
			|| ms_lst_append_tail(&expanded_token_lst,
				expanded_token_list) == -1)
			return (NULL);
		i++;
	}
	return (ms_lst_to_ntp(&expanded_token_lst, ms_identify, ms_noop_del));
}

static char	**ms_get_expanded_token(char ***expanded_tokens_list)
{
	t_list	*expanded_token_lst;
	char	**expanded_token_list;
	int		i;
	int		j;

	expanded_token_lst = NULL;
	i = 0;
	while (expanded_tokens_list[i] != NULL)
	{
		j = 0;
		while (expanded_tokens_list[i][j] != NULL)
		{
			if (ms_lst_append_tail(&expanded_token_lst,
					expanded_tokens_list[i][j]) == -1)
				return (NULL);
			j++;
		}
		i++;
	}
	expanded_token_list = ms_lst_to_ntp(&expanded_token_lst, ms_identify,
			ms_noop_del);
	if (expanded_token_list == NULL)
		return (NULL);
	return (expanded_token_list);
}
