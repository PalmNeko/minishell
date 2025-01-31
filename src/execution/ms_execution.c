/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:33:59 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 17:26:00 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "lexer.h"
#include "libms.h"
#include "semantic_analyze.h"
#include "syntax_analyze.h"
#include <stdlib.h>

/*notes
 * ENOMEMエラー時の処理を追加する必要あり
 */
int	ms_execution(const char *input)
{
	t_token			**tokens;
	t_syntax_node	*node;
	t_lsa			*lsa;
	int				ret;

	tokens = ms_lexical_analyze(input);
	if(tokens[0] != NULL)
	{
		node = ms_syntax_analyze(tokens);
		if (node->type != SY_DECLINED)
		{
			lsa = semantic_analyze(node);
			ret = ms_execute_from_lsa(lsa);
			ms_lsa_destroy(lsa);
		}
		else
			ret = 1;
		ms_syntax_node_destroy(node);
	}
	ms_destroy_ntp2((void **)tokens, free);
	return (ret);
}
