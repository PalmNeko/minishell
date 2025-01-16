/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_handle_on_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:54:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/16 07:20:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>

int	ms_set_handle_on_heredoc(void)
{
	const int	enable_sigint = 1;

	rl_persistent_signal_handlers = enable_sigint;
	return (0);
}
