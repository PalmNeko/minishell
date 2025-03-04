/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:07 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/04 23:03:52 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

static t_lsa_redirection_type	ms_get_redirection_type(
									t_syntax_node *redirection_node);
static t_lsa_redirection		*ms_lsa_redirection_create(
									t_lsa_redirection_type type);

t_lsa_redirection	*ms_lsa_redirection(t_syntax_node *redirection_node)
{
	t_lsa_redirection		*lsa_redirection;
	int						pos;

	lsa_redirection = ms_lsa_redirection_create
		(ms_get_redirection_type(redirection_node->children[0]));
	if (lsa_redirection->type == LSA_RD_HEREDOC)
	{
		pos = 1;
		if (redirection_node->children[pos]->type == SY_BLANK)
			pos++;
		if (ms_lsa_set_heredoc(lsa_redirection,
				redirection_node->children[pos]) != 0)
			return (ms_lsa_redirection_destroy(lsa_redirection), NULL);
	}
	else
	{
		lsa_redirection->filename = ms_lsa_word_list
			(redirection_node->children[1]);
		if (lsa_redirection->filename == NULL)
			return (free(lsa_redirection), NULL);
	}
	return (lsa_redirection);
}

static t_lsa_redirection
	*ms_lsa_redirection_create(t_lsa_redirection_type type)
{
	t_lsa_redirection	*lsa_redirection;

	lsa_redirection = (t_lsa_redirection *)malloc(sizeof(t_lsa_redirection));
	if (lsa_redirection == NULL)
		return (NULL);
	lsa_redirection->type = type;
	lsa_redirection->filename = NULL;
	lsa_redirection->delimiter = NULL;
	lsa_redirection->heredoc_input = NULL;
	lsa_redirection->is_expansion = false;
	return (lsa_redirection);
}

static t_lsa_redirection_type
	ms_get_redirection_type(t_syntax_node *redirection_node)
{
	const char	*token;

	token = redirection_node->token->token;
	if (ft_strcmp(token, ">") == 0)
		return (LSA_RD_OUTPUT);
	else if (ft_strcmp(token, ">>") == 0)
		return (LSA_RD_APPEND);
	else if (ft_strcmp(token, "<") == 0)
		return (LSA_RD_INPUT);
	return (LSA_RD_HEREDOC);
}
