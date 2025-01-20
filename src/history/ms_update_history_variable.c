/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_update_history_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:20:46 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/20 07:13:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "history.h"
#include "internal/history_internal.h"
#include <readline/readline.h>
#include <stdlib.h>

void	ms_update_histsize(void);
void	ms_update_histcmd(void);

void	ms_update_history_variable(void)
{
	ms_update_histsize();
	ms_update_histcmd();
}

void	ms_update_histsize(void)
{
	char		*histsize_str;
	int			histsize;

	histsize = -1;
	histsize_str = ms_getenv("HISTSIZE");
	if (histsize_str != NULL)
		histsize = ft_atoi(histsize_str);
	ms_stifle_history(histsize);
}

void	ms_update_histcmd(void)
{
	t_history	history;
	char		*histcmd_str;

	if (ms_unstifle_history() == 0)
		ms_reset_histcmd();
	history = ms_history();
	if (ms_unstifle_history() != 0 && history.history_cmd == 0)
	{
		history.history_cmd = 1;
		ms_set_history(&history);
	}
	if (ms_getenv("HISTCMD") == NULL)
	{
		history.enable_history_cmd = false;
		ms_set_history(&history);
		return ;
	}
	histcmd_str = ft_itoa(history.history_cmd);
	if (histcmd_str == NULL)
		return ;
	ms_setenv("HISTCMD", histcmd_str, 1);
	free(histcmd_str);
}
