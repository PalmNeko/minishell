/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathname_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:53 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/28 18:19:39 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <dirent.h>
#include <stdlib.h>

static int	ms_expand_path(t_syntax_node *word_node, t_list **node_lst);
static char	**ms_expand_path_wildcard(char *token);

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
			ms_lstappend_tail(&node_lst,
				new_child_node,
				ms_syntax_node_destroy_wrapper);
		}
		if (node_lst == NULL)
			return (NULL);
		i++;
	}
	new_children = (t_syntax_node **)
		ms_lst_to_ntp(&node_lst, ms_identify, ms_noop_del);
	if (new_children == NULL)
		return (NULL);
	ms_destroy_ntp2((void **)word_list->children,
		ms_syntax_node_destroy_wrapper);
	word_list->children = new_children;
	return (word_list);
}

static int	ms_expand_path(t_syntax_node *word_node, t_list **node_lst)
{
	int		i;
	char	*token;
	char	**expanded_tokens;
	t_list	*node_lst2;
	char	*expanded_string;
	t_token **expanded_token;
	int j;
	t_syntax_node *child;

	node_lst2 = NULL;
	expanded_tokens = NULL;
	token = (char *)word_node->token->token;
	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == '*')
		{
			expanded_tokens = ms_expand_path_wildcard(token);
			if (expanded_tokens == NULL)
				return (-1);
			if (expanded_tokens[0] == NULL)
			{
				ms_lstappend_tail(node_lst, ms_duplicate_node(word_node),
					ms_syntax_node_destroy_wrapper);
				if (node_lst == NULL)
					return (-1);
				break ;
			}
			expanded_string = ms_join_ntp((const char **)expanded_tokens, " ");
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
				ms_lstappend_tail(&node_lst2, child, ms_syntax_node_destroy_wrapper);
				if (node_lst2 == NULL)
					return (-1);
				j++;
			}
			ft_lstadd_back(node_lst, node_lst2);
			break ;
		}
		i++;
	}
	if (expanded_tokens == NULL)
	{
		ms_lstappend_tail(node_lst, ms_duplicate_node(word_node), ms_syntax_node_destroy_wrapper);
		if (node_lst == NULL)
			return (-1);
	}
	return (0);
}

char **ms_expand_path_wildcard(char *token)
{
	t_list	*expanded_token_lst;
	char	**expanded_string;
	char	**after_string;
	char	*before_string;
	DIR		*dir;
	int		index;
	struct dirent	*dp;
	char	*filename;
	int		i;

	index = 0;
	while (token[index] != '\0')
	{
		if (token[index] == '*')
		{
			before_string = ft_strndup(token, index);
			if (before_string == NULL)
				return (NULL);
			after_string = ms_expand_path_wildcard(token + index + 1);
			if (after_string == NULL)
				return (NULL);
			dir = opendir("./");
			if (dir == NULL)
				return (NULL);
			dp = readdir(dir);
			expanded_token_lst = NULL;
			while (dp != NULL)
			{
				if (ft_strncmp(dp->d_name, before_string,
						ft_strlen(before_string)) == 0)
				{
					i = 0;
					while (after_string[i] != NULL)
					{
						if (ft_strcmp(dp->d_name + ft_strlen(dp->d_name)
							- ft_strlen(after_string[i]), after_string[i]) == 0)
						{
							if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name,
								"..") != 0)
							{
								filename = ft_strdup(dp->d_name);
								if (filename == NULL)
									return (NULL);
								ms_lstappend_tail(&expanded_token_lst, filename, free);
								if (expanded_token_lst == NULL)
									return (NULL);
							}
						}
						i++;
					}
				}
				dp = readdir(dir);
			}
			closedir(dir);
			free(before_string);
			ms_destroy_ntp2((void **)after_string, free);
			expanded_string = ms_lst_to_ntp(&expanded_token_lst, ms_identify,
					ms_noop_del);
			if (expanded_string == NULL)
				return (NULL);
			return (expanded_string);
		}
		index++;
	}
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
