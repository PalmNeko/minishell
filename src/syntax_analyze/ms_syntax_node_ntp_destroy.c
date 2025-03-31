/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_ntp_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:51:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 14:59:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

void	ms_syntax_node_ntp_destroy(t_syntax_node **nodes)
{
	int	i;

	if (nodes == NULL)
		return ;
	i = 0;
	while (nodes[i] != NULL)
	{
		ms_syntax_node_destroy(nodes[i]);
		i++;
	}
	free(nodes);
	return ;
}
