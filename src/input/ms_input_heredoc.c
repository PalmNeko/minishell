/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:43:11 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/10 18:43:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "input.h"
#include "libms.h"
#include <stdlib.h>
#include <readline/readline.h>

char	*ms_read_with_heredoc(t_heredoc *heredoc);

char	*ms_input_heredoc(t_minishell mnsh, char *input)
{
	t_heredoc	heredoc;
	char		*heredoc_input;

	(void)mnsh;
	ms_init_heredoc(&heredoc);
	if (ms_set_delimita_list(&heredoc, input) != 0)
		return (ms_finalize_heredoc(&heredoc), NULL);
	heredoc_input = ms_read_with_heredoc(&heredoc);
	ms_finalize_heredoc(&heredoc);
	if (heredoc_input == NULL)
		return (NULL);
	return (heredoc_input);
}

char	*ms_read_with_heredoc(t_heredoc *heredoc)
{
	char			*readline_input;
	char			*input;
	bool			is_break;
	t_delimita_list	*delimita_list;

	input = ft_strdup("");
	if (input == NULL)
		return (NULL);
	delimita_list = heredoc->delimita_list;
	while (delimita_list != NULL)
	{
		readline_input = ms_read_with_delimita(delimita_list->content);
		if (readline_input == NULL)
			return (input);
		is_break = ms_replace_joined_str(&input, readline_input) == NULL;
		free(readline_input);
		if (is_break)
			break ;
		delimita_list = delimita_list->next;
	}
	return (input);
}
