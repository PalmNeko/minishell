/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:55:29 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/16 09:23:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L

#include <signal.h>
#include <readline/readline.h>
#include <stdlib.h>

static void	ms_handle_sigint(int sig);
static void	set_signal_handler(int sig, void (*handler)(int));

int	ms_set_handle(void)
{
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

void	ms_handle_sigint(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}
