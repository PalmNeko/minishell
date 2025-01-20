/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset_handle_on_heredoc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:55:54 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/16 07:02:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>

int	ms_unset_handle_on_heredoc(void)
{
	const int	disable_sigint = 0;

	rl_persistent_signal_handlers = disable_sigint;
	return (0);
}
