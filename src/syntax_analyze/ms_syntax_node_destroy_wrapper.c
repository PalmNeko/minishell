/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_destroy_wrapper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:28:32 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 00:15:08 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"

void	ms_syntax_node_destroy_wrapper(void *node)
{
	t_syntax_node	*syntax_node;

	syntax_node = (t_syntax_node *)node;
	ms_syntax_node_destroy(syntax_node);
}
