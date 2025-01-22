/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_assignment_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:12:15 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:12:17 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

void	ms_lsa_assignment_destroy(t_lsa_assignment *assignment)
{
	if (assignment == NULL)
		return ;
	if (assignment->name != NULL)
		ms_lsa_wordlist_destroy(assignment->name);
	if (assignment->value != NULL)
		ms_lsa_wordlist_destroy(assignment->value);
	free(assignment);
}
