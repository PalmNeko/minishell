/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_cdwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:15:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/07 15:15:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include "libft.h"
#include "libms.h"
#include <stdlib.h>

void	ms_set_cdwd(const char *cdwd)
{
	char	**old_cdwd;

	old_cdwd = ms_get_raw_cdwd();
	free(*old_cdwd);
	*old_cdwd = ft_strdup(cdwd);
	return ;
}
