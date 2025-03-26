/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/26 01:34:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "semantic_analyze.h"
#include <fcntl.h>
#include <stdlib.h>

static int	ms_redirect_input(t_lsa_redirection *redirect);
static int	ms_redirect_output(t_lsa_redirection *redirect);
static int	ms_redirect_append(t_lsa_redirection *redirect);
static int	ms_redirect_heredoc(t_lsa_redirection *redirect);

int	ms_run_redirects(t_lsa_redirection **redirects)
{
	int		i;
	int		ret;

	i = 0;
	while (redirects[i])
	{
		if (redirects[i]->type == LSA_RD_INPUT)
			ret = ms_redirect_input(redirects[i]);
		else if (redirects[i]->type == LSA_RD_OUTPUT)
			ret = ms_redirect_output(redirects[i]);
		else if (redirects[i]->type == LSA_RD_APPEND)
			ret = ms_redirect_append(redirects[i]);
		else if (redirects[i]->type == LSA_RD_HEREDOC)
			ret = ms_redirect_heredoc(redirects[i]);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	ms_redirect_input(t_lsa_redirection *redirect)
{
	int		fd;
	char	*filename;

	filename = ms_expansion(redirect->filename)[0];
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	ms_redirect_output(t_lsa_redirection *redirect)
{
	int		fd;
	char	*filename;

	filename = ms_expansion(redirect->filename)[0];
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	free(filename);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	ms_redirect_append(t_lsa_redirection *redirect)
{
	int		fd;
	char	*filename;

	filename = ms_expansion(redirect->filename)[0];
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	free(filename);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

static int	ms_redirect_heredoc(t_lsa_redirection *redirect)
{
	int				fd;
	char			tmp_name[264];
	t_syntax_node	**heredoc_input;

	ft_strlcpy(tmp_name, "/tmp/heredoc_XXXXXX", 264);
	fd = ft_mkostemp(tmp_name, O_CREAT | O_EXCL | O_SYNC);
	if (fd == -1)
		return (-1);
	heredoc_input = redirect->heredoc_input;
	while (*heredoc_input != NULL)
	{
		ft_putstr_fd((*heredoc_input)->token->token, fd);
		heredoc_input++;
	}
	close(fd);
	fd = open(tmp_name, O_RDONLY);
	unlink(tmp_name);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
