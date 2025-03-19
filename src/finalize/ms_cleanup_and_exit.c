/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cleanup_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:46:44 by tookuyam          #+#    #+#             */
/*   Updated: 2025/03/19 14:21:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "libms.h"
#include "history.h"
#include "builtin_internal.h"
#include <stdlib.h>
#include <stdio.h>

static void	ms_export_history(void);

void	ms_cleanup_and_exit(int status)
{
	if (ms_is_interactive() && ! ms_has_meta(status, IS_CHILD))
	{
		printf("exit\n");
		ms_add_mnsh_history("exit");
		ms_export_history();
	}
	ms_clear_history();
	ms_clear_cdwd();
	ms_clear_environ(NULL);
	exit(ms_get_status_from_meta(status));
}

static void	ms_export_history(void)
{
	const int	base = 10;
	int			histfilesize;
	char		*histfilesize_str;
	char		*endptr;

	if (ms_getenv("HISTFILE") == NULL)
		return ;
	ms_append_history(ms_unstifle_history(), ms_getenv("HISTFILE"));
	if (ms_getenv("HISTFILESIZE") == NULL)
		return ;
	histfilesize_str = ms_getenv("HISTFILESIZE");
	histfilesize = ft_strtol(histfilesize_str, &endptr, base);
	if (*endptr != '\0' || histfilesize < 0)
		return ;
	ms_history_truncate_file(ms_getenv("HISTFILE"), histfilesize);
}
