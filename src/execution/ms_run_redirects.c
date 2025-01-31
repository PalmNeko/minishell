/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/01/31 14:51:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "semantic_analyze.h"
#include <fcntl.h>
#include <stdlib.h>

static int	ms_redirect_input(char *filename);
static int	ms_redirect_output(char *filename);
static int	ms_redirect_append(char *filename);
// static void	ms_redirect_heredoc(t_lsa_redirection *redirect);

int	ms_run_redirects(t_lsa_redirection **redirects)
{
	int		i;
	char	*filename;
	int		ret;

	i = 0;
	while (redirects[i])
	{
		filename = ms_expansion(redirects[i]->filename)[0];
		if (filename == NULL)
			return (-1);
		if (redirects[i]->type == LSA_RD_INPUT)
			ret = ms_redirect_input(filename);
		else if (redirects[i]->type == LSA_RD_OUTPUT)
			ret = ms_redirect_output(filename);
		else if (redirects[i]->type == LSA_RD_APPEND)
			ret = ms_redirect_append(filename);
		// else if (redirects[i]->type == LSA_RD_HEREDOC)
		//  ret = ms_redirect_heredoc(redirects[i]);
		free(filename);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	ms_redirect_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	ms_redirect_output(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	ms_redirect_append(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

// static void	ms_redirect_heredoc(t_lsa_redirection *redirect)
// {
// 	int	fd[2];

// 	pipe(fd);
// 	write(fd[1], redirect->heredoc_input, ft_strlen(redirect->heredoc_input));
// 	dup2(fd[0], STDIN_FILENO);
// 	close(fd[0]);
// 	close(fd[1]);
// }