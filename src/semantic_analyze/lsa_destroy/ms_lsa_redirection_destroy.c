/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_redirection_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 13:22:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include "syntax_analyze.h"
#include "libms.h"
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
	if (redirection->heredoc_input != NULL)
		free(redirection->heredoc_input);
	free(redirection);
}
