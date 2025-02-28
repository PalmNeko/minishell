/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_readline_behavior.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:18:44 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 10:41:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "readline.h"
#include <readline/readline.h>
#include <unistd.h>
#include <termios.h>

int	ms_setup_readline_behavior(void)
{
    if (ms_is_interactive())
        ms_setup_readline_handler();
    else
    {
        rl_prep_term_function = NULL;
        rl_deprep_term_function = NULL;
    }
	return (0);
}
