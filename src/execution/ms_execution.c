/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:33:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 16:24:04 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexical_analyze.h"
#include "libms.h"
#include "semantic_analyze.h"
#include "syntax_analyze.h"
#include <stdlib.h>

static void	ms_destroy_tokens(t_token **tokens);

int	ms_execution(const char *input)
{
	t_token			**tokens;
	t_syntax_node	*node;
	t_lsa			*lsa;
	int				ret;

	ret = 0;
	tokens = ms_lexical_analyze(input);
	if (tokens == NULL || tokens[0] == NULL)
		return (ms_destroy_tokens(tokens), 1);
	node = ms_syntax_analyze(tokens);
	if (node == NULL)
		return (ms_destroy_tokens(tokens), 1);
	if (node->type == SY_DECLINED)
		return (ms_syntax_node_destroy(node),
			ms_destroy_tokens(tokens), ms_set_exit_status(2), 2);
	lsa = semantic_analyze(node);
	if (lsa == NULL)
		return (ms_syntax_node_destroy(node),
			ms_destroy_tokens(tokens), ms_set_exit_status(1), 1);
	ret = ms_execute_from_lsa(lsa);
	ms_lsa_destroy(lsa);
	ms_syntax_node_destroy(node);
	ms_destroy_tokens(tokens);
	return (ret);
}

static void	ms_destroy_tokens(t_token **tokens)
{
	ms_destroy_ntp2((void **)tokens, ms_destroy_token_wrapper);
}
