/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_command_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:12:25 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:12:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

static void	ms_lsa_wordlist_destroy_wrapper(void *wordlist);
static void	ms_lsa_assignment_destroy_wrapper(void *assignment);
static void	ms_lsa_redirection_destroy_wrapper(void *redirection);

void	ms_lsa_command_destroy(t_lsa_command *command)
{
	if (command == NULL)
		return ;
	if (command->args != NULL)
		ms_destroy_ntp2((void **)command->args,
			ms_lsa_wordlist_destroy_wrapper);
	if (command->assignments != NULL)
		ms_destroy_ntp2((void **)command->assignments,
			ms_lsa_assignment_destroy_wrapper);
	if (command->redirects != NULL)
		ms_destroy_ntp2((void **)command->redirects,
			ms_lsa_redirection_destroy_wrapper);
	free(command);
}

void	ms_lsa_wordlist_destroy_wrapper(void *wordlist)
{
	ms_lsa_wordlist_destroy((t_lsa_word_list *)wordlist);
}

void	ms_lsa_assignment_destroy_wrapper(void *assignment)
{
	ms_lsa_assignment_destroy((t_lsa_assignment *)assignment);
}

void	ms_lsa_redirection_destroy_wrapper(void *redirection)
{
	ms_lsa_redirection_destroy((t_lsa_redirection *)redirection);
}
