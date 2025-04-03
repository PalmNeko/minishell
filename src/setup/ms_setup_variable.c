/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:29:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/28 07:21:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "setup.h"
#include <stdlib.h>
#include <stdio.h>

static void	ms_setup_only_interactive_var(void);
static void	ms_setup_common_variable(void);
static void	ms_setup_shlvl(void);
static void	ms_shlvl_max_error(int shlvl);

/**
 * setup environment variable.
 */
void	ms_setup_variable(void)
{
	ms_setup_common_variable();
	if (ms_is_interactive() == true)
		ms_setup_only_interactive_var();
}

static void	ms_setup_only_interactive_var(void)
{
	ms_setenv("HISTCMD", "1", 0);
	ms_setenv("HISTSIZE", "500", 0);
	ms_setenv("HISTFILESIZE", "500", 0);
	ms_setenv("HISTFILE", "~/.mnsh_history", 0);
	ms_setenv("TMPDIR", "/tmp", 0);
	ms_setenv("PS1", "minishell $ ", 0);
	ms_setenv("PS2", "> ", 0);
}

static void	ms_setup_common_variable(void)
{
	char	*cwd;

	cwd = ms_get_current_dir_name();
	if (cwd != NULL)
		ms_setenv("PWD", cwd, 1);
	ms_setenv("?", "0", 0);
	free(cwd);
	ms_setup_shlvl();
	ms_setenv("MNSH_SUBSHELL", "0", 0);
}

static void	ms_setup_shlvl(void)
{
	char	*shlvl_str;
	char	*newshlvl_str;
	int		shlvl;

	shlvl_str = ms_getenv("SHLVL");
	if (shlvl_str == NULL)
		shlvl = 1;
	else
	{
		shlvl = ms_shell_atoi(shlvl_str);
		if (shlvl < 0 || shlvl == INT32_MAX)
			shlvl = 0;
		else
			shlvl++;
	}
	if (shlvl >= 1000)
	{
		ms_shlvl_max_error(shlvl);
		shlvl = 1;
	}
	newshlvl_str = ft_itoa(shlvl);
	ms_setenv("SHLVL", newshlvl_str, 1);
	free(newshlvl_str);
	return ;
}

static void	ms_shlvl_max_error(int shlvl)
{
	char	*shlvl_str;
	char	msg[100];

	shlvl_str = ft_itoa(shlvl);
	if (shlvl_str == NULL)
		return ;
	ft_strlcpy(msg, "shell level (", 100);
	ft_strlcat(msg, shlvl_str, 100);
	ft_strlcat(msg, ") too high, resetting to 1", 100);
	free(shlvl_str);
	ms_perror_cmd("warning", msg);
}
