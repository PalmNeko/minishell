/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:26:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/02 19:29:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static char	*g_errinfo;

void	ft_set_errinfo(char *einfo)
{
	g_errinfo = einfo;
}

char	*ft_get_errinfo(void)
{
	return (g_errinfo);
}

void	ft_clear_errinfo(void)
{
	g_errinfo = NULL;
}
