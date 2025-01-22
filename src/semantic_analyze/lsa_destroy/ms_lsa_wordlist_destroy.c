/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_wordlist_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:17 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/22 09:13:18 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semantic_analyze.h"
#include <stdlib.h>

void	ms_lsa_wordlist_destroy(t_lsa_word_list *wordlist)
{
	if (wordlist == NULL)
		return ;
	free(wordlist);
}
