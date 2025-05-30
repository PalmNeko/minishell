/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:41 by rnakatan          #+#    #+#             */
/*   Updated: 2025/03/31 18:06:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "semantic_analyze.h"
#include "libms.h"
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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
	char	**expanded_texts;

	expanded_texts = ms_expansion(redirect->filename);
	if (expanded_texts == NULL || ms_ntpsize((void **)expanded_texts) != 1)
		return (ms_wordlist_perror(redirect->filename, "ambiguous redirect")
			, ms_destroy_ntp(expanded_texts), -1);
	filename = ft_strdup(expanded_texts[0]);
	ms_destroy_ntp(expanded_texts);
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ms_perror_cmd(filename, strerror(errno)), free(filename), -1);
	free(filename);
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
	char	**expanded_texts;

	expanded_texts = ms_expansion(redirect->filename);
	if (expanded_texts == NULL || ms_ntpsize((void **)expanded_texts) != 1)
		return (ms_wordlist_perror(redirect->filename, "ambiguous redirect")
			, ms_destroy_ntp(expanded_texts), -1);
	filename = ft_strdup(expanded_texts[0]);
	ms_destroy_ntp(expanded_texts);
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		return (ms_perror_cmd(filename, strerror(errno)), free(filename), -1);
	free(filename);
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
	char	**expanded_texts;

	expanded_texts = ms_expansion(redirect->filename);
	if (expanded_texts == NULL || ms_ntpsize((void **)expanded_texts) != 1)
		return (ms_wordlist_perror(redirect->filename, "ambiguous redirect")
			, ms_destroy_ntp(expanded_texts), -1);
	filename = ft_strdup(expanded_texts[0]);
	ms_destroy_ntp(expanded_texts);
	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (ms_perror_cmd(filename, strerror(errno)), free(filename), -1);
	free(filename);
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
