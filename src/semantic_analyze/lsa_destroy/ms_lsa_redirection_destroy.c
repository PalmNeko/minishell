/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_redirection_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:13:09 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include <stdlib.h>

/*notes
 * not yet about heredoc.
 */
void	ms_lsa_redirection_destroy(t_lsa_redirection *redirection)
{
	if (redirection == NULL)
		return ;
	if (redirection->filename != NULL)
		ms_lsa_wordlist_destroy(redirection->filename);
	if (redirection->delimiter != NULL)
		ms_lsa_wordlist_destroy(redirection->delimiter);
	// if (redirection->heredoc_input != NULL)
	// 	ms_syntax_node_destroy(redirection->heredoc_input);
	free(redirection);
}
