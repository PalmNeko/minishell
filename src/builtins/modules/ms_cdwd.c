/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cdwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:36:53 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 07:25:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"
#include "ms_error.h"
#include "builtin_internal.h"
#include <stdlib.h>

static char	*g_cdwd = NULL;

int	ms_init_cdwd(void)
{
	char	*cwd;

	cwd = ms_get_current_dir_name();
	if (cwd == NULL)
	{
		ms_perror_cwd("shell-init");
		ft_putendl_fd("sh: 0: getcwd() failed: No such file or directory", 2);
		return (-1);
	}
	ms_set_cdwd(cwd);
	free(cwd);
	if (g_cdwd == NULL)
		return (-1);
	return (0);
}

char	*ms_get_cdwd(void)
{
	return (g_cdwd);
}

void	ms_set_cdwd(const char *cdwd)
{
	free(g_cdwd);
	g_cdwd = ft_strdup(cdwd);
}

void	ms_clear_cdwd(void)
{
	free(g_cdwd);
}
