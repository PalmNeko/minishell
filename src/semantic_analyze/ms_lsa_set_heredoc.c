/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_set_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 05:22:50 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/29 13:35:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static int		ms_lsa_set_heredoc_input(t_lsa_redirection *lsa_redirection,
					const char *delimiter);
static t_list	*ms_lsa_get_heredoc_input_lst(const char *delimiter);
static char		*ms_lst_node_to_string(t_list *lst);

int	ms_lsa_set_heredoc(t_lsa_redirection *lsa_redirection,
		t_syntax_node *delimiter_node)
{
	char	*delimiter;

	lsa_redirection->delimiter = ms_lsa_word_list(delimiter_node);
	if (lsa_redirection->delimiter == NULL)
		return (-1);
	delimiter = ms_word_list_to_delimiter_string(lsa_redirection->delimiter);
	if (delimiter != NULL)
	{
		if (ms_lsa_set_heredoc_input(lsa_redirection, delimiter) == 0)
			return (free(delimiter), 0);
		free(delimiter);
	}
	ms_lsa_wordlist_destroy(lsa_redirection->delimiter);
	return (-1);
}

static int	ms_lsa_set_heredoc_input(t_lsa_redirection *lsa_redirection,
		const char *delimiter)
{
	t_list			*heredoc_lst;
	t_syntax_node	**heredoc_input;

	heredoc_lst = ms_lsa_get_heredoc_input_lst(delimiter);
	heredoc_input = ms_lst_to_ntp(&heredoc_lst, ms_identify, ms_noop_del);
	lsa_redirection->heredoc_input = heredoc_input;
	if (lsa_redirection->heredoc_input == NULL)
		return (ft_lstclear(&heredoc_lst, ms_noop_del), -1);
	return (0);
}

static t_list	*ms_lsa_get_heredoc_input_lst(const char *delimiter)
{
	t_list	*heredoc_lst;
	t_list	*line_lst;
	char	*line_str;
	int		result;

	heredoc_lst = NULL;
	while (1)
	{
		line_lst = ms_get_next_line_node();
		if (line_lst == NULL)
			break ;
		line_str = ms_lst_node_to_string(line_lst);
		if (line_str == NULL)
			break ;
		result = ms_compare_heredoc_input(line_str, delimiter);
		free(line_str);
		if (result)
		{
			ft_lstclear(&line_lst, ms_noop_del);
			break ;
		}
		ft_lstadd_back(&heredoc_lst, line_lst);
		line_lst = NULL;
	}
	return (heredoc_lst);
}

static char	*ms_lst_node_to_string(t_list *lst)
{
	char			*output;
	t_syntax_node	*node;

	output = ft_strdup("");
	if (output == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node = lst->content;
		if (ms_replace_joined_str(&output, node->token->token) == NULL)
			return (free(output), NULL);
		lst = lst->next;
	}
	return (output);
}
