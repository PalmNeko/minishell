/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_readline_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:55:29 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/07 11:39:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_header.h"
#include "libft.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	g_rl_is_sigint;

static void	set_signal_handler(int sig, void (*handler)(int));
static int	ms_startup_hook_handler(void);
static int	ms_event_hook_handler(void);
static void	ms_handle_sigint(int sig);

int	ms_setup_readline_handler(void)
{
	rl_startup_hook = ms_startup_hook_handler;
	rl_event_hook = ms_event_hook_handler;
	rl_outstream = stderr;
	set_signal_handler(SIGINT, ms_handle_sigint);
	set_signal_handler(SIGQUIT, SIG_IGN);
	return (0);
}

void	set_signal_handler(int sig, void (*handler)(int))
{
	struct sigaction	act;

	act.sa_handler = handler;
	act.sa_flags = SA_NOCLDWAIT;
	sigemptyset(&act.sa_mask);
	sigaction(sig, &act, NULL);
}

static int	ms_startup_hook_handler(void)
{
	g_rl_is_sigint = 0;
	return (0);
}

static int	ms_event_hook_handler(void)
{
	if (g_rl_is_sigint)
	{
		rl_replace_line("", 0);
		rl_done = 1;
	}
	return (0);
}

static void	ms_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		g_rl_is_sigint = 1;
		rl_done = 1;
	}
}
