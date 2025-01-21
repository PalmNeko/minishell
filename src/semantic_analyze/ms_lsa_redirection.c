#include "semantic_analyze.h"
#include <stdlib.h>

static t_lsa_redirection_type	ms_lsa_redirection_type(const char *token);
static t_lsa_redirection		*ms_lsa_redirection_create(t_lsa_redirection_type type);

t_lsa_redirection	*ms_lsa_redirection(const t_syntax_node *redirection_node)
{
	t_lsa_redirection_type	type;
	t_lsa_redirection		*lsa_redirection;

	type = ms_lsa_redirection_type(redirection_node->children[0]->token->token);
	lsa_redirection = ms_lsa_redirection_create(type);
	if (lsa_redirection->type == LSA_RD_HEREDOC)
	{
		// get of heredoc_input
	}
	else
	{
		if (redirection_node->children[1]->type != SY_BLANK)
			lsa_redirection->filename = ms_lsa_word_list(redirection_node->children[1]);
		else
			lsa_redirection->filename = ms_lsa_word_list(redirection_node->children[2]);
		if(lsa_redirection->filename == NULL)
			return(free(lsa_redirection), NULL);
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
