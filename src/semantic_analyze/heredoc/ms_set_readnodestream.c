/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_readnodestream.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:46:51 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/28 06:22:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

static int				g_pos = 0;
static t_syntax_node	**g_stream = NULL;

void	ms_set_readnodestream(t_syntax_node *node)
{
	g_stream = node->children;
	g_pos = 0;
	return ;
}

void	ms_unset_readnodestream(void)
{
	g_pos = 0;
	g_stream = NULL;
}

t_syntax_node	*ms_read_node(void)
{
	if (g_stream == NULL)
		return (NULL);
	return (g_stream[g_pos++]);
}
