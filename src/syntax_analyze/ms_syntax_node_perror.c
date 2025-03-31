/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_perror.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:02 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 17:56:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

void	ms_syntax_node_perror(const t_syntax_node *node, const char *msg)
{
	char	*node_text;

	node_text = ms_syntax_node_to_string(node);
	if (node_text == NULL)
		return ;
	ms_perror_cmd(node_text, msg);
	free(node_text);
	return ;
}
