/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cdwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:36:53 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 06:40:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*g_cdwd = NULL;

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
