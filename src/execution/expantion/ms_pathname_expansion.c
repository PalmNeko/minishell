/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathname_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:27:53 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/15 23:16:57 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libms.h"
#include "syntax_analyze.h"
#include <dirent.h>
#include <stdlib.h>
#include "pathname_expansion.h"

static int		ms_expand_path(t_syntax_node *word_node, t_list **node_lst);
static t_list	*ms_create_expanded_node_lst(char *expanded_string);

// not considered multi wildcard case...

t_syntax_node	*ms_pathname_expansion(t_syntax_node *word_list)
{
	int				i;
	t_syntax_node	**new_children;
	t_list			*child_node_lst;

	child_node_lst = NULL;
	i = 0;
	while (word_list->children[i])
	{
		if (ms_expand_path(word_list->children[i], &child_node_lst) == -1)
			return (ft_lstclear(&child_node_lst, ms_noop_del), NULL);
		i++;
	}
	new_children = (t_syntax_node **)ms_lst_to_ntp(&child_node_lst,
			(void *)ms_duplicate_node, ms_syntax_node_destroy_wrapper);
	if (new_children == NULL)
		return (NULL);
	ms_destroy_ntp2((void **)word_list->children,
		ms_syntax_node_destroy_wrapper);
	word_list->children = new_children;
	return (word_list);
}

static int	ms_expand_path(t_syntax_node *word_node, t_list **child_node_lst)
{
	char			*expanded_string;
	t_list			*expanded_node_lst;

	expanded_node_lst = NULL;
	if (word_node->type == SY_WORD
		&& ft_strchr(word_node->token->token, '*'))
	{
		expanded_string = ms_expand_path2((char *)word_node->token->token);
		if (expanded_string == NULL)
			return (-1);
		if (expanded_string[0] == '\0')
			return (ms_lst_append_tail(child_node_lst,
					ms_duplicate_node(word_node)));
		expanded_node_lst = ms_create_expanded_node_lst(expanded_string);
		free(expanded_string);
		ft_lstadd_back(child_node_lst, expanded_node_lst);
	}
	else
	{
		if (ms_lst_append_tail(child_node_lst,
				ms_duplicate_node(word_node)) == -1)
			return (-1);
	}
	return (0);
}

static t_list	*ms_create_expanded_node_lst(char *expanded_string)
{
	t_token			**expanded_tokens;
	t_syntax_node	*child_node;
	t_list			*expanded_node_lst;
	int				j;

	expanded_tokens = ms_lexical_analyze(expanded_string);
	if (expanded_tokens == NULL)
		return (NULL);
	j = 0;
	expanded_node_lst = NULL;
	while (expanded_tokens[j] != NULL)
	{
		child_node = ms_syntax_node_create(SY_WORD);
		if (child_node == NULL)
			return (NULL);
		child_node->token = ms_duplicate_token(expanded_tokens[j]);
		child_node->start_pos = expanded_tokens[j]->start_pos;
		child_node->end_pos = child_node->start_pos + 1;
		if (ms_lst_append_tail(&expanded_node_lst, child_node) == -1)
			return (NULL);
		j++;
	}
	ms_destroy_ntp2((void **)expanded_tokens, ms_destroy_token_wrapper);
	return (expanded_node_lst);
}
