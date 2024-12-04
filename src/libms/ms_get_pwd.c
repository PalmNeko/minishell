/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/04 15:45:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"

static char	*g_pwd;

char	**ms_get_pwd(void)
{
	if (g_pwd == NULL)
		g_pwd = ms_get_current_dir_name();
	return (&g_pwd);
}
