/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathname_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:53 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/13 07:00:05 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <dirent.h>
#include <stdlib.h>

static int		ms_expand_path(t_syntax_node *word_node, t_list **node_lst);
static char		**ms_expand_path_wildcard(char *token);
static char		**ms_get_file_list_from_dir(DIR *dir);
static char		**ms_get_expanded_path_list(char **file_list,
					char *token_string, int index);
static char **ms_get_single_string_list(char *token);

// *.*などは後で考慮する。

t_syntax_node	*ms_pathname_expansion(t_syntax_node *word_list)
{
	int				i;
	t_syntax_node	*new_child_node;
	t_syntax_node	**new_children;
	t_list			*node_lst;

	node_lst = NULL;
	i = 0;
	while (word_list->children[i])
	{
		if (word_list->children[i]->type == SY_WORD)
			ms_expand_path(word_list->children[i], &node_lst);
		else
		{
			new_child_node = ms_duplicate_node(word_list->children[i]);
			if (new_child_node == NULL)
				return (NULL);
			ms_lstappend_tail(&node_lst, new_child_node,
				ms_syntax_node_destroy_wrapper);
		}
		if (node_lst == NULL)
			return (NULL);
		i++;
	}
	new_children = (t_syntax_node **)ms_lst_to_ntp(&node_lst, ms_identify,
			ms_noop_del);
	if (new_children == NULL)
		return (NULL);
	ms_destroy_ntp2((void **)word_list->children,
		ms_syntax_node_destroy_wrapper);
	word_list->children = new_children;
	return (word_list);
}

static char	**ms_get_dir_list(char *token);
static char	***ms_get_expanded_tokens_list(char **dir_list);
static char	**ms_get_expanded_token(char ***expanded_tokens_list);
#include <stdio.h>

static int	ms_expand_path(t_syntax_node *word_node, t_list **node_lst)
{

	char			***expanded_tokens_list;
	char			*expanded_string;
	t_token			**expanded_token;
	char			**expanded_token_list;
	t_syntax_node	*child;
	char			**dir_list;
	int				j;

	dir_list = ms_get_dir_list((char *)word_node->token->token);
	if (dir_list == NULL)
		return (-1);
	expanded_tokens_list = ms_get_expanded_tokens_list(dir_list);
	if (expanded_tokens_list == NULL)
		return (-1);
	expanded_token_list = ms_get_expanded_token(expanded_tokens_list);
	if (expanded_token_list == NULL)
		return (-1);
	expanded_string = ms_join_ntp((const char **)expanded_token_list, " ");
	if (expanded_string == NULL)
		return (-1);
	expanded_token = ms_lexical_analyze(expanded_string);
	if (expanded_token == NULL)
		return (-1);
	j = 0;
	while (expanded_token[j] != NULL)
	{
		child = ms_syntax_node_create(SY_WORD);
		if (child == NULL)
			return (-1);
		child->token = expanded_token[j];
		child->start_pos = expanded_token[j]->start_pos;
		child->end_pos = child->start_pos + 1;
		if (ms_lst_append_tail(node_lst, child) == -1)
			return (-1);
		j++;
	}
	return (0);
}

static char	***ms_get_expanded_tokens_list(char **dir_list)
{
	int				i;
	t_list			*expanded_token_lst;
	char			**expanded_token_list;

	expanded_token_lst = NULL;
	i = 0;
	while (dir_list[i] != NULL)
	{
		expanded_token_list = ms_expand_path_wildcard(dir_list[i]);
		if (expanded_token_list == NULL)
			return (NULL);
		if(ms_lst_append_tail(&expanded_token_lst, expanded_token_list) == -1)
			return (NULL); //freehituyou
		i++;
	}
	return (ms_lst_to_ntp(&expanded_token_lst, ms_identify, ms_noop_del));
}

static char	**ms_get_dir_list(char *token)
{
	char	**dir_list;
	int		i;

	dir_list = ft_split(token, '/');
	if (dir_list == NULL)
		return (NULL);
	if (token[0] == '/')
		ft_strjoin("/", dir_list[0]);
	else
		ft_strjoin("./", dir_list[0]);
	if (dir_list[0] == NULL)
		return (ms_destroy_ntp(dir_list), NULL);
	i = 1;
	while (dir_list[i] != NULL)
	{
		if (!ms_replace_joined_str(&dir_list[i], "/"))
			return (ms_destroy_ntp(dir_list), NULL);
		i++;
	}
	return (dir_list);
}

#include <stdio.h>
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

static char	**ms_get_expanded_path_wildcard(char *token, int index);
static char	**ms_get_single_string_list(char *token);
static char	**ms_get_file_list_from_dir(DIR *dir);
static char	**ms_get_expanded_path_list(char **file_list,
				char *token_string, int index);

char	**ms_expand_path_wildcard(char *token)
{
	int				index;
	char			**expanded_path_list;

	index = 0;
	while (token[index] != '\0')
	{
		//複数のワイルドカードに対応させるとしたらここをダブルポインタで渡す？
		if (token[index] == '*')
		{
			expanded_path_list = ms_get_expanded_path_wildcard(token, index);
			return (expanded_path_list);
		}
		index++;
	}
	expanded_path_list = ms_get_single_string_list(token);
	if (expanded_path_list == NULL)
		return (NULL);
	return (expanded_path_list);
}

static char	**ms_get_expanded_path_wildcard(char *token, int index)
{
	DIR		*dir;
	char	**file_list;
	char	**expanded_path_list;

	dir = opendir("./");
	if (dir == NULL)
		return (NULL);
	file_list = ms_get_file_list_from_dir(dir);
	if (file_list == NULL)
		return (NULL);
	expanded_path_list = ms_get_expanded_path_list(file_list, token, index);
	closedir(dir);
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

static char	**ms_get_file_list_from_dir(DIR *dir)
{
	struct dirent	*dp;
	t_list			*expanded_token_lst;
	char			**file_list;
	char			*filename;

	dp = readdir(dir);
	expanded_token_lst = NULL;
	while (dp != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0
			&& ft_strcmp(dp->d_name, "..") != 0)
		{
			filename = ft_strdup(dp->d_name);
			if (filename == NULL)
				return (NULL);
			ms_lstappend_tail(&expanded_token_lst, filename, free);
			if (expanded_token_lst == NULL)
				return (NULL);
		}
		dp = readdir(dir);
	}
	file_list = ms_lst_to_ntp(&expanded_token_lst, ms_identify, ms_noop_del);
	if (file_list == NULL)
		return (NULL);
	return (file_list);
}

static char	**ms_get_expanded_path_list(char **file_list, char *token_string,
				int index)
{
	t_list	*expanded_token_lst;
	char	**expanded_path_list;
	char	*filename;
	int		i;
	int		j;
	char	*before_string;
	char	**after_strings;

	before_string = ft_strndup(token_string, index);
	if (before_string == NULL)
		return (NULL);
	after_strings = ms_expand_path_wildcard(token_string + ft_strlen(before_string) + 1);
	if (after_strings == NULL)
	{
		free(before_string);
		return (NULL);
	}
	expanded_token_lst = NULL;
	i = 0;
	while (file_list[i] != NULL)
	{
		if (ft_strncmp(file_list[i], before_string,
				ft_strlen(before_string)) == 0)
		{
			j = 0;
			while (after_strings[j] != NULL)
			{
				if (ft_strcmp(file_list[i] + ft_strlen(file_list[i])
						- ft_strlen(after_strings[j]),
						after_strings[j]) == 0)
				{
					filename = ft_strdup(file_list[i]);
					if (filename == NULL)
						return (NULL);
					ms_lstappend_tail(&expanded_token_lst, filename,
						free);
					if (expanded_token_lst == NULL)
						return (NULL);
				}
				j++;
			}
		}
		i++;
	}
	expanded_path_list = ms_lst_to_ntp(&expanded_token_lst, ms_identify,
			ms_noop_del);
	if (expanded_path_list == NULL)
		return (NULL);
	return (expanded_path_list);
}
