/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:38:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/28 08:14:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "setup.h"
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>

static char	*g_readline_buffer = NULL;

static char	*ms_cut_and_replace(char **buffer);
static void	ms_clear_str(char **buffer);

char	*ms_readline(const char *prompt)
{
	if (g_readline_buffer != NULL)
		;
	else if (ms_is_interactive())
		g_readline_buffer = readline(prompt);
	else
		g_readline_buffer = readline(NULL);
	return (ms_cut_and_replace(&g_readline_buffer));
}

void	ms_clear_readline_buffer(void)
{
	ms_clear_str(&g_readline_buffer);
}

static void	ms_clear_str(char **str)
{
	if (str == NULL)
		return ;
	free(*str);
	*str = NULL;
	return ;
}

static char	*ms_cut_and_replace(char **buffer)
{
	char	*cut_end;
	char	*line;
	char	*new_buffer;

	if (*buffer == NULL)
		return (NULL);
	cut_end = ft_strchr(*buffer, '\n');
	if (cut_end == NULL)
	{
		line = *buffer;
		*buffer = NULL;
		return (line);
	}
	line = ft_strndup(*buffer, cut_end - *buffer);
	if (line == NULL)
		return (ms_clear_str(buffer), NULL);
	cut_end++;
	if (*cut_end == '\0')
		return (ms_clear_str(buffer), line);
	new_buffer = ft_strdup(cut_end);
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}
