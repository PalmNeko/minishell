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
static bool	ms_is_quoted_closed(const char *line);
static int	ms_is_loop(int status);

static int	ms_get_status_from_meta(int status)
{
	return (status & 0xff);
}

int	ms_input(t_minishell mnsh)
{
	char	*line;
	int		status;
	char	*stat_str;

	(void)mnsh;
	status = 0;
	while (ms_is_loop(status))
	{
		line = ms_get_user_input(mnsh);
		if (line == NULL)
			break ;
		ft_strrchr(line, '\n')[0] = '\0';
		if (! g_rl_is_sigint)
		{
			ms_add_mnsh_history(line);
			status = ms_execution(line);
			stat_str = ft_itoa(ms_get_status_from_meta(status));
			ms_setenv("?", stat_str, 1);
			free(stat_str);
		}
		free(line);
	}
	return (ms_get_status_from_meta(status));
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
	if (!ms_is_quoted_closed(line))
		return (line);
	heredoc_input = ms_input_heredoc(mnsh, line);
	if (heredoc_input == NULL)
		return (NULL);
	if (ms_replace_joined_str(&line, heredoc_input) == NULL)
		return (free(line), free(heredoc_input), NULL);
	free(heredoc_input);
	return (line);
}

static bool	ms_is_quoted_closed(const char *line)
{
	char	*first_line_end;

	first_line_end = ft_strchr(line, '\n');
	if (first_line_end == NULL)
		return (false);
	while (*line != '\0')
	{
		if (ft_includes(*line, "\"'"))
		{
			line = ft_strchr(line + 1, *line);
			if (line == NULL || line > first_line_end)
				return (false);
		}
		line++;
	}
	return (true);
}

static int ms_is_loop(int status)
{
	if (status & IS_CHILD)
		return (0);
	return(1);
}
