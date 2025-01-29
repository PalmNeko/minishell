/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_redirection_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:08 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/29 12:05:19 by tookuyam         ###   ########.fr       */
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
		ms_destroy_ntp2((void **)redirection->heredoc_input,
			(void (*)(void *))ms_syntax_node_destroy);
	free(redirection);
}
