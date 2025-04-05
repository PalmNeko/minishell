/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:33:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 13:04:56 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexical_analyze.h"
#include "libms.h"
#include "semantic_analyze.h"
#include "syntax_analyze.h"
#include <stdio.h>
#include <stdlib.h>

/*notes
 * must add ENOMEM case process.
 */

int	ms_execution(const char *input)
{
	t_token			**tokens;
	t_syntax_node	*node;
	t_lsa			*lsa;
	int				ret;

	ret = 0;
	tokens = ms_lexical_analyze(input);
	if (tokens[0] != NULL)
	{
		node = ms_syntax_analyze(tokens);
		if (node->type != SY_DECLINED)
		{
			lsa = semantic_analyze(node);
			ret = ms_execute_from_lsa(lsa);
			ms_lsa_destroy(lsa);
		}
		else
		{
			ret = 2;
			ms_set_exit_status(ret);
		}
		ms_syntax_node_destroy(node);
	}
	ms_destroy_ntp2((void **)tokens, ms_destroy_token_wrapper);
	return (ret);
}
