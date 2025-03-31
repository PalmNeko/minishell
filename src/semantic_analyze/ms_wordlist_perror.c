/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_wordlist_perror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:53:36 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/31 17:54:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include "semantic_analyze.h"

void	ms_wordlist_perror(const t_lsa_word_list *word_list, const char *msg)
{
	ms_syntax_node_perror(
		word_list->word_list, msg);
	return ;
}
