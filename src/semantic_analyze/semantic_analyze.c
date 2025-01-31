/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:14:17 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 13:15:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "syntax_analyze.h"
#include <stdlib.h>

/* notes
 * not yet about heredoc.
 */
t_lsa	*semantic_analyze(t_syntax_node *node)
{
	t_lsa			*lsa;
	t_lsa_list		**lists;
	t_syntax_node	*user_input_node;

	lsa = malloc(sizeof(t_lsa));
	if (lsa == NULL)
		return (NULL);
	user_input_node = ms_syntax_node_get_child(node, SY_USER_INPUT);
	if (user_input_node != NULL)
		ms_set_readnodestream(user_input_node);
	lists = ms_lsa_lists(node->children[0]);
	ms_unset_readnodestream();
	if (lists == NULL)
		return (NULL);
	lsa->lists = lists;
	return (lsa);
}
