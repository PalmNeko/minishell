/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setup_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:29:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/18 18:34:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

/**
 * PWD の値を設定
 */
void	ms_setup_variable(void)
{
	char	*cwd;

	cwd = ms_get_current_dir_name();
	if (cwd != NULL)
		ms_setenv("PWD", cwd, 1);
	ms_setenv("HISTCMD", "1", 0);
	ms_setenv("HISTSIZE", "500", 0);
	ms_setenv("HISTFILESIZE", "500", 0);
	ms_setenv("HISTFILE", "~/.mnsh_history", 0);
	ms_setenv("TMPDIR", "/tmp", 0);
	ms_setenv("PS1", "minishell $ ", 0);
	ms_setenv("PS2", "> ", 0);
	ms_setenv("MNSH_SUBSHELL", "0", 0);
}
