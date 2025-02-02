/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_check_declined.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:33:35 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:33:35 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

int	ms_syntax_node_check_declined(t_syntax_node *node)
{
	if (node->type == SY_DECLINED)
	{
		ms_syntax_node_destroy(node);
		return (1);
	}
	return (0);
}