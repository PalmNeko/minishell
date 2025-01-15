/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_with_delimita.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:59:29 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/11 12:59:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libft.h"
#include "input.h"
#include <unistd.h>
#include <readline/readline.h>
#include <stdlib.h>

void	ms_print_heredoc_eof_warning(void);

char	*ms_read_with_delimita(char *delimita)
{
	char	*readline_input;
	char	*input;
	bool	is_break;

	input = ft_strdup("");
	if (input == NULL)
		return (NULL);
	while (1)
	{
		readline_input = readline(" > "); // PS2
		if (!readline_input)
		{
			ms_print_heredoc_eof_warning();
			break ;
		}
		is_break = ft_strcmp(readline_input, delimita) == 0;
		is_break |= ms_append_with_newline(&input, readline_input) == NULL;
		free(readline_input);
		if (is_break)
			break ;
	}
	return (input);
}

void	ms_print_heredoc_eof_warning(void)
{
	ms_perror_cmd2("minishell", "warning",
		"here-document delimited by end-of-file (wanted `EOF')");
}
