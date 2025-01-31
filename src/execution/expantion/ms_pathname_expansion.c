/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathname_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:53 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 00:05:35 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <dirent.h>
#include <stdlib.h>

static t_syntax_node *ms_expand_path(t_syntax_node *word);
static char **ms_expand_path_wildcard(char *token);
static t_list *_ms_expand_path_wildcard(DIR *dir, char *before_string, char **after_string);

t_syntax_node	*ms_pathname_expansion(t_syntax_node *word_list)
{
	int i;
	char *token;

	i = 0;
	
	while (word_list->children[i])
	{
		if(word_list->children[i]->type == SY_WORD)
		{
			token = (char *)word_list->children[i]->token->token;
			if(ft_strchr(token, '*') != NULL)
				word_list->children[i] = ms_expand_path(word_list->children[i]);
		}
		i++;
	}
	return (word_list);
}

static t_syntax_node *ms_expand_path(t_syntax_node *word)
{
	t_syntax_node *new_word_list;
	char **expanded_tokens;
	t_token **expand_tokens;
	char *expanded_string;
	t_syntax_node *child;
	t_syntax_node_list *child_lst;
	int i;

	expanded_tokens = ms_expand_path_wildcard((char *)word->token->token);
	if(expanded_tokens[0] == NULL)
		return (word);
	ms_syntax_node_destroy(word);
	if(expanded_tokens == NULL)
		return (NULL);
	expanded_string = ms_join_ntp((const char**)expanded_tokens, " ");
	ms_destroy_ntp2((void **)expanded_tokens, free);
	if(expanded_string == NULL)
		return (NULL);
	expand_tokens = ms_lexical_analyze(expanded_string);
	child_lst = NULL;
	i = 0;
	while(expand_tokens[i] != NULL)
	{
		child = ms_syntax_node_create(SY_WORD);
		if(child == NULL)
			return (NULL);
		child->token = expand_tokens[i];
		ms_lstappend_tail(&child_lst, child, ms_syntax_node_destroy_wrapper);
		i++;
	}
	new_word_list = ms_syntax_node_create(SY_WORD_LIST);
	if(new_word_list == NULL)
		return (NULL);
	new_word_list = ms_syntax_node_set_of_children(new_word_list, &child_lst);
	if(new_word_list == NULL)
		return (NULL);
	return (new_word_list);
}

char **ms_expand_path_wildcard(char *token)
{
	t_list *expanded_token_lst;
	char **expanded_string;
	char **after_string;
	char *before_string;
	DIR *dir;
	int index;

	index = 0;
	while(token[index] != '\0')
	{
		if(token[index] == '*')
		{
			before_string = ft_strndup(token, index);
			if(before_string == NULL)
				return (NULL);
			after_string = ms_expand_path_wildcard(token + index + 1);
			if(after_string == NULL)
				return (NULL);
			dir = opendir("./");
			if(dir == NULL)
				return (NULL);
			expanded_token_lst = _ms_expand_path_wildcard(dir, before_string, after_string);
			if(expanded_token_lst == NULL)
				return (NULL);
			closedir(dir);
			free(before_string);
			ms_destroy_ntp2((void **)after_string, free);
			expanded_string = ms_lst_to_ntp(&expanded_token_lst, ms_identify, ms_noop_del);
			if(expanded_string == NULL)
				return (NULL);
			return (expanded_string);
		}
		index++;
	}
	expanded_string = (char **)malloc(sizeof(char *) * 2);
	if(expanded_string == NULL)
		return (NULL);
	expanded_string[0] = ft_strdup(token);
	if(expanded_string[0] == NULL)
	{
		free(expanded_string);
		return (NULL);
	}
	expanded_string[1] = NULL;
	return (expanded_string);
}

static t_list *_ms_expand_path_wildcard(DIR *dir, char *before_string, char **after_string)
{
	t_list *expanded_token_lst;
	char *filename;
	int i;
	struct dirent *dp;

	dp = readdir(dir);
	expanded_token_lst = NULL;
	while(dp != NULL)
	{
		if(ft_strncmp(dp->d_name, before_string, ft_strlen(before_string)) == 0)
		{
			i = 0;
			while(after_string[i] != NULL)
			{
				if(ft_strcmp(dp->d_name + ft_strlen(dp->d_name) - ft_strlen(after_string[i]), after_string[i]) == 0)
				{
					if(ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..") != 0)
					{
						filename = ft_strdup(dp->d_name);
						if(filename == NULL)
							return (NULL);
						ms_lstappend_tail(&expanded_token_lst, filename, free);
						if(expanded_token_lst == NULL)
							return (NULL);
					}
				}
				i++;
			}
		}
		dp = readdir(dir);
	}
	return (expanded_token_lst);
}

// // static char **ms_expand_path_wildcard(char *token, int i)
// // {
// // 	char *dirpath;
// // 	char *serach_start;
// // 	char *serach_end;
// // 	DIR *dir;
// // 	struct dirent *dp;
// // 	t_list *expanded_token_lst;
// // 	char *expanded_token;
// // 	char **expanded_tokens;
// // 	int end_len;
// // 	int start_len;

// // 	dirpath = get_serach_dir(token, i);
// // 	if(dirpath == NULL)
// // 		return (token);
// // 	serach_start = &token[ft_strlen(dirpath)];
// // 	serach_end = &token[i + 1];
// // 	dir = opendir(dirpath);
// // 	if (dir == NULL)
// // 		return (token);
// // 	dp = readdir(dir);
// // 	while (dp != NULL)
// // 	{
// // 		start_len = ft_strlen(serach_start);
// // 		if (ft_strncmp(dp->d_name, serach_start, start_len) == 0)
// // 		{
// // 			end_len = ft_strlen(dp->d_name) - ft_strlen(serach_end);
// // 			if(ft_strcmp(dp->d_name + end_len, serach_end) == 0)
// // 			{
// // 				expanded_token = ft_strjoin(dirpath, dp->d_name);
// // 				if(expanded_token == NULL)
// // 					return (NULL);
// // 				ms_lstappend_tail(&expanded_token_lst, expanded_token, free);
// // 				if(expanded_token_lst == NULL)
// // 					return (NULL);
// // 			}
// // 		}
// // 		dp = readdir(dir);
// // 	}
// // 	closedir(dir);
// // 	free(dirpath);
// // 	expanded_tokens = ms_lst_to_ntp(expanded_token_lst, ms_identify, free);
// // 	if(expanded_tokens == NULL)
// // 		return (NULL);
// // 	return (expanded_tokens);
// // }

// static char *get_serach_dir(char *token, int i)
// {
// 	while (i >= 0)
// 	{
// 		if (token[i] == '/')
// 			return (strndup(token, i));
// 		i--;
// 	}
// 	return (strdup("."));
// }

// static int ms_count_char(char *str, char c)
// {
// 	int count;
// 	int i;

// 	count = 0;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == c)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }
