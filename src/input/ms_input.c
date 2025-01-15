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
#include "execution.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

char	*ms_get_user_input(t_minishell mnsh);

void	ms_input(t_minishell mnsh)
{
	char	*line;
	int	status;

	(void)mnsh;
	while (1)
	{
		line = ms_get_user_input(mnsh);
		if (line == NULL)
			break ;
		ft_strrchr(line, '\n')[0] = '\0';
		add_history(line);
		status = ms_execution(line);
		free(line);
	}
	printf("exit\n");
	return ;
}

char	*ms_get_user_input(t_minishell mnsh)
{
	char	*line;
	char	*heredoc_input;

	while (1)
	{
		line = readline("bulitin> ");
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
