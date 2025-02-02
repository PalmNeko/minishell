/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:29 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 05:56:51 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semantic_analyze.h>
#include <stdlib.h>

t_lsa_assignment	*ms_lsa_assignment(t_syntax_node *assignment_word_node)
{
	t_lsa_assignment	*lsa_assignment;

	lsa_assignment = malloc(sizeof(t_lsa_assignment));
	if (lsa_assignment == NULL)
		return (NULL);
	lsa_assignment->name = ms_lsa_word_list(assignment_word_node->children[0]);
	if (lsa_assignment->name == NULL)
		return (free(lsa_assignment), NULL);
	lsa_assignment->value = ms_lsa_word_list(assignment_word_node->children[2]);
	if (lsa_assignment->value == NULL)
		return (free(lsa_assignment->name), free(lsa_assignment), NULL);
	return (lsa_assignment);
}
