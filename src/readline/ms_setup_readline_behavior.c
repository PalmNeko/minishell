/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_readline_behavior.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:18:44 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/30 20:13:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "readline.h"
#include <readline/readline.h>
#include <unistd.h>
#include <termio.h>

static void	ms_disable_echo(int meta_flag);
static void	ms_enable_echo(void);

int	ms_setup_readline_behavior(void)
{
    if (ms_is_interactive())
        ms_setup_readline_handler();
    else
    {
        rl_prep_term_function = ms_disable_echo;
        rl_deprep_term_function = ms_enable_echo;
    }
	return (0);
}

static void	ms_disable_echo(int meta_flag)
{
    struct termios tty;

	(void)meta_flag;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

static void	ms_enable_echo(void)
{
    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
