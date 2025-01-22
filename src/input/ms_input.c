/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:45:59 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/09 17:45:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "libms.h"
#include "readline.h"
#include "execution.h"
#include "history.h"
#include <readline/readline.h>
#include <stdlib.h>

static char	*ms_get_user_input(t_minishell mnsh);

void	ms_input(t_minishell mnsh)
{
	char	*line;

	(void)mnsh;
	while (1)
	{
		line = ms_get_user_input(mnsh);
		if (line == NULL)
			break ;
		ft_strrchr(line, '\n')[0] = '\0';
		if (! g_rl_is_sigint)
		{
			ms_add_mnsh_history(line);
			ms_execution(line);
		}
		free(line);
	}
	return ;
}

static char	*ms_get_user_input(t_minishell mnsh)
{
	char	*line;
	char	*heredoc_input;

	ms_update_history_variable();
	while (1)
	{
		line = ms_readline(ms_getenv("PS1"));
		if (!line)
			return (NULL);
		if (line[0] != '\0')
			break ;
		free(line);
	}
	if (ms_replace_joined_str(&line, "\n") == NULL)
		return (free(line), NULL);
	heredoc_input = ms_input_heredoc(mnsh, line);
	if (heredoc_input == NULL)
		return (NULL);
	if (ms_replace_joined_str(&line, heredoc_input) == NULL)
		return (free(line), free(heredoc_input), NULL);
	return (line);
}
