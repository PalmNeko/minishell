/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:07 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 12:10:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze_internal.h"
#include "semantic_analyze.h"
#include <stdlib.h>

static t_lsa_redirection_type	ms_lsa_redirection_type(const char *token);
static t_lsa_redirection		*ms_lsa_redirection_create(t_lsa_redirection_type type);

t_lsa_redirection	*ms_lsa_redirection(const t_syntax_node *redirection_node)
{
	t_lsa_redirection_type	type;
	t_lsa_redirection		*lsa_redirection;
	int						pos;

	type = ms_lsa_redirection_type(redirection_node->children[0]->token->token);
	lsa_redirection = ms_lsa_redirection_create(type);
	if (lsa_redirection->type == LSA_RD_HEREDOC)
	{
		pos = 1;
		if (redirection_node->children[pos]->type == SY_BLANK)
			pos++;
		if (ms_lsa_set_heredoc(lsa_redirection, redirection_node->children[pos]) != 0)
			return (ms_lsa_redirection_destroy(lsa_redirection), NULL);
	}
	else
	{
		if (redirection_node->children[1]->type != SY_BLANK)
			lsa_redirection->filename = ms_lsa_word_list(redirection_node->children[1]);
		else
			lsa_redirection->filename = ms_lsa_word_list(redirection_node->children[2]);
		if (lsa_redirection->filename == NULL)
			return (free(lsa_redirection), NULL); // TODO: i think we should use ms_lsa_redirection_destroy
	}
	return (lsa_redirection);
}

static t_lsa_redirection	*ms_lsa_redirection_create(t_lsa_redirection_type type)
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

static t_lsa_redirection_type	ms_lsa_redirection_type(const char *token)
{
	if (ft_strcmp(token, ">") == 0)
		return (LSA_RD_OUTPUT);
	else if (ft_strcmp(token, ">>") == 0)
		return (LSA_RD_APPEND);
	else if (ft_strcmp(token, "<") == 0)
		return (LSA_RD_INPUT);
	return (LSA_RD_HEREDOC);
}
