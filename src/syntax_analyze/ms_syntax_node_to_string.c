/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_to_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:41:03 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 17:57:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "syntax_analyze.h"
#include <stdlib.h>

char	*ms_syntax_node_to_string(const t_syntax_node *node)
{
	char			*str;
	char			*child_str;
	t_syntax_node	**children;

	if (node == NULL)
		return (NULL);
	if (node->token != NULL)
		return (ft_strdup(node->token->token));
	str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	children = node->children;
	while (*children != NULL)
	{
		child_str = ms_syntax_node_to_string(*children);
		if (child_str == NULL)
			return (free(str), NULL);
		if (ms_replace_joined_str(&str, child_str) == NULL)
			return (free(str), free(child_str), NULL);
		free(child_str);
		children++;
	}
	return (str);
}
